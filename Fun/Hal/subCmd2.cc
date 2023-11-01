{{$resp := or (dbGet 0 "hal").Value sdict}}
{{$inv := or (dbGet .User.ID "inv").Value sdict}}
{{$point := or (dbGet .User.ID "spooky").Value 0 | toInt}}
{{$items := cslice "xp_points" "xp_boost1" "xp_boost2" "xp_boost3"  "xp_boost4" "xp_boost5"  "xp_boost6" "boss_bait" "reversal_card" "trick_card" "treat_card"}}
{{if eq (lower .Cmd) ";shop"}}
	{{if ne .Channel.ID 1014899143870791680}}`;shop` should only be used in <#1014899143870791680>{{return}}{{end}}
	{{$c := false}}{{if reFind `-c` .StrippedMsg}}{{$c = true}}{{end}}
	{{$desc := ""}}	
	{{if $c}}
      {{range $k, $v := $resp.shop}}
          {{- $desc = printf "%s**%s**\n**Price** : `%s` spooky points.\n**Command** : `;buy %s amount`\n\n" $desc $v.name (humanizeThousands $v.price) $k}}
      {{end}}
	{{else}}
      {{range $k, $v := $resp.shop}}
          {{- $desc = printf "%s**%s** : %s\n**Price** : `%s` spooky points.\n**Command** : `;buy %s amount`\n\n" $desc $v.name $v.description (humanizeThousands $v.price) $k}}
      {{end}}
	{{end}}
	{{$embed := cembed
      "title" "🎃 Spooky Emporium - Haunting Supplies"
      "description" (print "Welcome to the Spooky Emporium, where ghostly treasures await on your haunting journey. Explore our eerie offerings below:\n\n" $desc)
      "color" 0xFF8C00
      "footer" (sdict "text" "use ;shop -c for compact mode")}}
	{{sendMessage nil $embed}}
{{else if eq (lower .Cmd) ";buy"}}
	{{$args := parseArgs 1 ";buy name amount" (carg "string" "item") (carg "int" "amount")}}
	{{$amount := 1}}{{if $args.IsSet 1}}{{$amount = $args.Get 1}}{{end}}
	{{$name := ($args.Get 0 | lower)}}
	{{if $item := ($resp.shop.Get $name)}}
		{{$required := mult $amount $item.price}}
		{{if lt $point $required}}
			{{sendMessage nil (print .User.Mention ", you dont have enough points..")}}{{return}}
		{{else}}
			{{if and (eq $name "xp_points") ($xpCD := (dbGet .User.ID "xpShopCD"))}}
				{{sendMessage nil (printf "⌛ Greetings, %s! The mystical energies of the spectral realm resonate with your desire to acquire the coveted item. However, the ethereal forces whisper a message of patience. The spectral market is currently in a state of repose, and the item you seek is undergoing a brief period of rejuvenation. Fear not, brave adventurer, for the cooldown period remains till <t:%d:R>. Embrace the shadows and await the opportune moment when the cosmic energies align once more. May your spectral journey be filled with anticipation and enchanted moments!" .User.Mention $xpCD.ExpiresAt.Unix)}}
				{{return}}
			{{end}}
			{{if and (eq $name "xp_points") (gt $amount 1)}}
				{{sendMessage nil (printf "🛍️ Greetings, %s! As you tread the spectral marketplace, the ethereal whispers guide your choices. However, the mystical forces decree that the coveted item may only be acquired **one at a time**. The cosmic balance demands a measured approach to the spectral treasures. Embrace the wisdom of moderation, noble adventurer, as you navigate the enigmatic offerings of the spectral bazaar. May your acquisitions be as balanced as the dance of shadows in the spectral realm!" .User.Mention)}}
				{{return}}
			{{end}}
			{{if eq $name "xp_points"}}
				{{dbSetExpire .User.ID "xpShopCD" 1 17280}}
			{{end}}
			{{if $inv.HasKey $name}}
				{{$inv.Set $name (add ($inv.Get $name) $amount)}}
			{{else}}
				{{$inv.Set $name $amount}}
			{{end}}
			{{$shh := dbIncr .User.ID "spooky" (mult -1 $required)}}
			{{sendMessage nil (print  "🎉 Congratulations, " .User.Mention "! You've successfully purchased " $amount " " $item.name "(s). May these items aid you in your spectral endeavors!")}}
		{{end}}
	{{else}}
		{{sendMessage nil (print .User.Mention ", no such item in shop..\nThe available items are `" (joinStr "` `" $items) "`")}}
	{{end}} 
	{{dbSet .User.ID "inv" $inv}}
{{else if eq (lower .Cmd) ";use"}}
	{{if not .CmdArgs}}{{return}}{{end}}
	{{$name := (index .CmdArgs 0) | lower}}
	{{$available := $inv.Get $name}}
	{{if not $available}}you dont have that item to use...{{return}}{{end}}
	{{if le $available 0}}you dont have that item to use...{{return}}{{end}}
	{{if eq $name "xp_points"}}
		{{$args := parseArgs 1 (";use xp_points [amount]") (carg "string" "item") (carg "int" "amount")}}
		{{$amount := 1}}{{if $args.IsSet 1}}{{$amount = $args.Get 1}}{{end}}
		{{if lt $available $amount}}⚠️ Oops, {{.User.Mention}}, it seems you don't have enough `{{$name}}` to use. Check your spectral inventory and try again!{{return}}{{end}}
		{{if le  $amount 0}}you can't do that...{{return}}{{end}}
		{{sendMessage nil (print .User.Mention " |🌌 Cultivate wisely, for the Cultivation Essence Vials have granted you mysterious " (mult 1000 $amount | humanizeThousands) " points on your journey of supernatural enlightenment.")}}
		{{$_ := dbIncr .User.ID "xp" (mult 1000 $amount)}}
		{{$rem := sub $available $amount}}
		{{if le $rem 0}}{{$inv.Del $name}}{{else}}{{$inv.Set $name $rem}}{{end}}
	{{else if eq $name "boss_bait"}}
      {{$channel := 997263718826123354}}
      {{if ne .Channel.ID $channel}}`;use boss_bait` should only be used in <#997263718826123354>{{return}}{{end}}
      {{$bossList := cslice "Jack-O'-Lantern King" "Wraith of the Haunted Forest" "Cursed Witch's Brewmaster" "Spectral Reaper of Souls" "Phantom Jester of Tricks" "Bleeding Stone Golem" "Sister of the Veil" "Kaliwing, the Haunted Parrot" "Moonlit Werewolf Alpha" "Sorcerer's Ghostly Apprentice"}}
      {{if not $resp.bosses}}something went wrong...{{return}}{{end}}
      {{$boss := index (shuffle $bossList) 0}}
      {{if not (dbGet $channel "boss")}}
        {{$mID := sendMessageNoEscapeRetID $channel (complexMessage "content" (print "  🎃 Ghastly presence summoned! Brace for a chilling encounter, " .User.Mention ". The spectral realm awaits your courage. Face the otherworldly adversary and revel in the haunting thrill of battle!") "embed" (cembed "title" $boss "description" ($resp.bosses.Get $boss).desc "thumbnail" (sdict "url" ($resp.bosses.Get $boss).url) "timestamp" currentTime "footer" (sdict "text" (print "⏳ 60 seconds."))))}}
        {{addMessageReactions $channel $mID "⚔️"}}
		{{$rem := sub $available 1}}
		{{if le $rem 0}}{{$inv.Del $name}}{{else}}{{$inv.Set $name $rem}}{{end}}
        {{dbSetExpire $channel "boss" (sdict "boss" $boss "mID" $mID "user" .User) 600}}
        {{execCC 95 nil 60 true}}
      {{else}}
        {{sendMessage nil (print "🎃 Beware, " .User.Mention "! The ethereal realm is already stirred with the presence of a formidable spectral boss. Focus your energies on defeating the current adversary before attempting to summon another. The spectral forces demand a singular confrontation at a time for an honorable and immersive battle!")}}
      {{end}}
	{{else if eq $name "reversal_card"}}
		{{$embed := sdict "title" "Karmic Reversal Card" "color" 0x9932CC}}
        {{$rand := randInt 11 | toInt}}
        {{if eq $rand 0 1 2 3}}{{/* reverse */}}
          {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickInv) 0) "``\x60") (or .Member.Nick .User.Username))}}
          {{dbSet .User.ID "spooky" (mult -1 $point)}}
        {{else if eq $rand 4 5 6}}{{/* double */}}
          {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickDouble) 0) "``\x60") (or .Member.Nick .User.Username))}}
          {{dbSet .User.ID "spooky" (mult 2 $point)}}
        {{else if eq $rand 7 8}}{{/* half */}}
          {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickHalf) 0) "``\x60") (or .Member.Nick .User.Username))}}
          {{dbSet .User.ID "spooky" (mult 0.5 $point | toInt)}}
        {{else if eq $rand 9}}{{/* reset */}}
          {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickReset) 0) "``\x60") (or .Member.Nick .User.Username))}}
          {{dbSet .User.ID "spooky" 0}}
		{{else if eq $rand 10}}
          {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickNothing) 0) "``\x60") (or .Member.Nick .User.Username))}}
        {{end}}
		{{$embed.Set "thumbnail" (sdict "url" (.User.AvatarURL "2048"))}}
		{{sendMessage nil (cembed $embed)}}
		{{$rem := sub $available 1}}
		{{if le $rem 0}}{{$inv.Del $name}}{{else}}{{$inv.Set $name $rem}}{{end}}
	{{else if eq $name "trick_card"}}
		{{$user := .Member}}
		{{$args := parseArgs 1 (";use trick_card [user]") (carg "string" "item") (carg "member" "target")}}
		{{if $args.IsSet 1}}{{$user = $args.Get 1}}{{end}}
		{{if eq 0 (randInt 2 | toInt)}}{{$user = .Member}}{{end}}
		{{$tricks := (cslice "points" "mute" "points" "mirror" "points" "mute" "points")}}
		{{$reward := index (shuffle $tricks) 0}}
		{{$embed := sdict "title" "Illusory Trickster Card"}}
		{{$username := or $user.Nick $user.User.Username}}
		{{if eq $reward "mute"}}
			{{$points := randInt -1000 0}}
			{{$time := randInt 1 11}}
			{{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.negTrickMute) 0) "``\x60") $username $time (mult -1 $points))}}
			{{$_ := dbIncr $user.User.ID "spooky" $points}}
			{{try}}{{$_ := execAdmin "timeout" $user.User.ID (print $time "m") "🎃Got tricked🎃"}}{{catch}}{{print "...can't timeout you :c"}}{{end}}
		{{else if eq $reward "points"}}
			{{if eq (toInt (randInt 2)) 1}}
				{{$points := (randInt 0 10000)}}
				{{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.posTrick) 0) "``\x60") $username $points)}}
				{{$shh := dbIncr $user.User.ID "spooky" $points}}
			{{else}}
				{{$points := (randInt -5000 0)}}
				{{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.negTrick) 0) "``\x60") $username (mult -1 $points))}}
				{{$shh := dbIncr $user.User.ID "spooky" $points}}
			{{end}}
		{{else if eq  $reward "mirror"}}
			{{$points := or (dbGet $user.User.ID "spooky").Value 0}}
            {{$rand := randInt 11 | toInt}}
            {{if eq $rand 0 1 2 3}}{{/* reverse */}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickInv) 0) "``\x60") $username)}}
              {{dbSet $user.User.ID "spooky" (mult -1 $point)}}
            {{else if eq $rand 4 5 6}}{{/* double */}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickDouble) 0) "``\x60") $username)}}
              {{dbSet $user.User.ID "spooky" (mult 2 $point)}}
            {{else if eq $rand 7 8}}{{/* half */}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickHalf) 0) "``\x60") $username)}}
              {{dbSet $user.User.ID "spooky" (mult 0.5 $point | toInt)}}
            {{else if eq $rand 9}}{{/* reset */}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickReset) 0) "``\x60") $username)}}
              {{dbSet $user.User.ID "spooky" 0}}
            {{else if eq $rand 10}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickNothing) 0) "``\x60") $username)}}
			{{end}}
		{{end}}
		{{$embed.Set "color" 0xFF8C00}}
		{{$embed.Set "footer" (sdict "text" "Spooky Shenanigans")}}
		{{$embed.Set "timestamp" currentTime}}
		{{$embed.Set "thumbnail" (sdict "url" (or ($user.AvatarURL "2048") ($user.User.AvatarURL "2048")))}}
		{{sendMessage nil (cembed $embed)}}
		{{$rem := sub $available 1}}
		{{if le $rem 0}}{{$inv.Del $name}}{{else}}{{$inv.Set $name $rem}}{{end}}
	{{else if eq $name "treat_card"}}
		{{$user := .Member}}
		{{$args := parseArgs 1 (";use treat_card [user] [amount]") (carg "string" "item") (carg "member" "target") (carg "int" "amount")}}
{{$amount := 1}}{{if $args.IsSet 2}}{{$amount = $args.Get 2}}{{end}}
{{if lt $available $amount}}you don't have that much to use{{return}}{{end}}
{{if le $amount 0}}NO{{return}}{{end}}
		{{if $args.IsSet 1}}{{$user = $args.Get 1}}{{end}}
		{{$embed := sdict "title" "Enchanted Treat Card"}}
		{{$username := or $user.Nick $user.User.Username}}
		{{$points := mult $amount (randInt 500 2501)}}
		{{$shh := dbIncr $user.User.ID "spooky" $points}}
		{{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.treat) 0) "``\x60") $username $points)}}
		{{$embed.Set "color" 0xFF8C00}}
		{{$embed.Set "footer" (sdict "text" "Spooky Shenanigans")}}
		{{$embed.Set "timestamp" currentTime}}
		{{$embed.Set "thumbnail" (sdict "url" (or ($user.AvatarURL "2048") ($user.User.AvatarURL "2048")))}}
		{{sendMessage nil (cembed $embed)}}
		{{$rem := sub $available $amount}}
		{{if le $rem 0}}{{$inv.Del $name}}{{else}}{{$inv.Set $name $rem}}{{end}}
	{{else if eq $name "xp_boost1" "xp_boost2" "xp_boost3" "xp_boost4" "xp_boost5" "xp_boost6"}}
		{{if (dbGet .User.ID "halBoost")}}You cant use more than one of these...{{return}}{{end}}
		{{$boostData := sdict
          "xp_boost1" (sdict "inc" 5 "dur" 86400) 
          "xp_boost2" (sdict "inc" 5 "dur" 604800) 
          "xp_boost3" (sdict "inc" 10 "dur" 86400) 
          "xp_boost4" (sdict "inc" 10 "dur" 604800) 
          "xp_boost5" (sdict "inc" 15 "dur" 86400) 
          "xp_boost6" (sdict "inc" 15 "dur" 604800)}}
        {{$curBoost := $boostData.Get $name}}
		{{dbSetExpire .User.ID "halBoost" $curBoost.inc $curBoost.dur}}
        {{$embed := cembed
          "title" "🌟 Celestial Growth Elixir"
          "description" (printf "🔮 %s has consumed a Celestial Growth Elixir! A surge of ethereal energy courses through %s, enhancing their cultivation. XP gain is increased by %d% for a limited time." .User.Mention (or .Member.Nick .User.Username) $curBoost.inc)
          "color" 0x00CED1
          "footer" (sdict "text" "Celestial Enlightenment")
        }}
		{{sendMessage nil $embed}}
		{{$rem := sub $available 1}}
		{{if le $rem 0}}{{$inv.Del $name}}{{else}}{{$inv.Set $name $rem}}{{end}}
	{{else}}
		{{sendMessage nil "Couldn't find that item..."}}
	{{end}}
	{{dbSet .User.ID "inv" $inv}}
{{else if eq (lower .Cmd) ";inv"}}
	{{$user := .User}}
	{{if .Message.Mentions}}{{$user = index .Message.Mentions 0}}{{end}}
	{{$desc := ""}}
	{{$inv = or (dbGet $user.ID "inv").Value sdict}}
	{{range $k, $v := $inv}}
        {{- if eq $k "xp_boost"}}{{- $inv.Set "xp_boost1" $v}}{{- $inv.Del $k}}{{- end}}
        {{- if eq $v 0}}{{- $inv.Del $k}}{{- end}}
		{{- $desc = printf "%s%-13s - %d\n" $desc $k $v}}
	{{end}}
	{{$embed := cembed
      "title" "🎒 Spectral Inventory"
      "thumbnail" (sdict "url" ($user.AvatarURL "2048"))
      "footer" (sdict "text" (print "requested by " (or .Member.Nick .User.Username)))
      "timestamp" currentTime
      "description" (printf "Here is spectral inventory of %s.\nExplore the otherworldly items you've collected on your haunting journey``\x60%s``\x60" $user.Mention (or $desc "you got nothing..."))
      "color" 0x663399}}
    {{dbSet $user.ID "inv" $inv}}
	{{sendMessage nil $embed}}
{{else if eq (lower .Cmd) ";give"}}
	{{$args := parseArgs 2 ";give @user points" (carg "member" "target") (carg "int" "points")}}
	{{$target := $args.Get 0}}
	{{$amount := $args.Get 1}}
	{{if le $amount 0}}NO{{return}}{{end}}
	{{if gt $amount $point}}
		{{sendMessage nil "You don't have that much spooky to share"}}
	{{else}}
		{{sendMessage nil (print .User.Mention " gave " $target.User.Mention " " (humanizeThousands $amount) " spooky points.")}}
		{{$_ := dbIncr .User.ID "spooky" (mult -1 $amount)}}
		{{$_ := dbIncr $target.User.ID "spooky" $amount}}
	{{end}}
{{else if eq (lower .Cmd) ";trade"}}
	{{$args := parseArgs 2 ";trade @user item [amount]" (carg "member" "target") (carg "string" "item") (carg "int" "amount")}}
	{{$target := $args.Get 0}}
	{{if eq .User.ID $target.User.ID}}Can't trade with yourself!{{return}}{{end}}
	{{$targetInv := or (dbGet $target.User.ID "inv").Value sdict}}
	{{$item := $args.Get 1 | lower}}
	{{$amount := 1}}{{if $args.IsSet 2}}{{$amount = $args.Get 2}}{{end}}
	{{if le $amount 0}}NO{{return}}{{end}}
	{{if not (in $items $item)}}no such item....{{return}}{{end}}
	{{$available := ($inv.Get $item)}}
	{{if lt $available $amount}}you dont have that many `{{$item}}` trade{{return}}{{end}}
	{{$inv.Set $item (sub ($inv.Get $item) $amount)}}
	{{$targetInv.Set $item (add ($targetInv.Get $item) $amount)}}
	{{sendMessage nil (print .User.Mention " gave " $amount " " $item "(s) to " $target.User.Mention ".")}}
	{{dbSet .User.ID "inv" $inv}}
	{{dbSet $target.User.ID "inv" $targetInv}}
{{else if eq (lower .Cmd) ";sell"}}
    {{$args := parseArgs 1 ";sell item [amount]" (carg "string" "item") (carg "int" "amount")}}
    {{$amount := 1}}{{if $args.IsSet 1}}{{$amount = $args.Get 1}}{{end}}
    {{if le $amount 0}}NO{{return}}{{end}}
    {{$item := $args.Get 0 | lower}}
    {{if not ($inv.HasKey $item)}}You don't have that item to sell..{{return}}{{end}}
    {{if eq $item "xp_points"}}You shouldn't do that.. or just give it to someone else{{return}}{{end}}
	{{$have := $inv.Get $item}}
    {{if lt $have $amount}}You don't have that many to sell..{{return}}{{end}}
    {{$price := ($resp.shop.Get $item).price}}
    {{$_ := dbIncr .User.ID "spooky" (mult $amount $price)}}
    {{$inv.Set $item (sub $have $amount)}}
    {{dbSet .User.ID "inv" $inv}}
    {{sendMessage nil (printf "💸 Huzzah, noble %s! Your spectral item, priced at %s spooky points, has found a new owner in the ethereal marketplace. As the transaction unfolds in the ghostly realm, `%s` x %d has successfully acquired the mystical item. May the exchanged spectral energies bring both parties good fortune in their otherworldly endeavors! 💸" .User.Mention (mult $amount $price | humanizeThousands) $item $amount)}}
{{end}}
