{{if eq .Reaction.Emoji.Name "⚔️"}}{{/* bosses */}}
	{{$channel := 997263718826123354}}
	{{$items := cslice "xp_points" "xp_boost1" "xp_boost2" "xp_boost3" "xp_boost4" "xp_boost5" "xp_boost6" "boss_bait" "reversal_card" "trick_card" "treat_card"}}
    {{if not .Message.Embeds}}{{return}}{{end}}
    {{$embed := index .Message.Embeds 0 | structToSdict}}
    {{if reFind `👻 A wild` $embed.Title}}
    {{$point := randInt 2000}}
    {{range .Message.Reactions}}
      {{- if and (eq .Emoji.Name "⚔️") .Me}}
        {{- deleteAllMessageReactions nil $.Message.ID .Emoji.Name}}
        {{- $shh := dbIncr $.User.ID "spooky" $point}}
		{{- $embed.Set "description" (printf "Congratulations! %s have triumphed over the enemy. The ethereal presence dissipates, and a sense of victory fills the air. %s spooky points have been added to the spectral ledger!" $.User.Mention (humanizeThousands $point))}}
		{{- if eq (randInt 100 | toInt) 0 1 2 3 4}}
			{{- $drop := index (shuffle $items) 0}}
			{{- $embed.Set "description" (printf "Congratulations! %s have triumphed over the enemy. The ethereal presence dissipates, and a sense of victory fills the air. %s spooky points have been added to the spectral ledger!\n\n🎁 You've also found a rare item: `%s`" $.User.Mention (humanizeThousands $point) $drop)}}
            {{- $inv := (dbGet $.User.ID "inv").Value}}
            {{- $inv.Set $drop (add ($inv.Get $drop) 1)}}
            {{- dbSet $.User.ID "inv" $inv}}
		{{- end}}
        {{- editMessage nil $.Message.ID (cembed $embed)}}
		{{- dbDel 0 "halMob"}}
		{{- break}}
      {{- end -}}
    {{end}}
  {{end}}
  {{if $db := (dbGet $channel "boss").Value}}
      {{if ne $db.mID .Message.ID}}{{return}}{{end}}
      {{$users := or (dbGet $channel "bossList").Value sdict}}
      {{$users.Set (str .User.ID) 0}}
      {{dbSet $channel "bossList" $users}}
  {{end}}
{{else if eq .Reaction.Emoji.Name "🔔"}}{{/* Notification Handler */}}
    {{$channel := 997263718826123354}}
    {{if $db := (dbGet $channel "boss").Value}}
  	  {{if ne $db.mID .Message.ID}}{{return}}{{end}}
	  {{if hasRoleID 1164215848714649622}}
		  {{removeRoleID 1164215848714649622}}
	  {{else}}
		  {{addRoleID 1164215848714649622}}
	  {{end}}
  {{end}}
{{else if eq .Reaction.Emoji.Name "🦇" "👻" "🎃"}}{{/* Halloween Stuffs */}}
    {{$emojis := cslice "🦇" "👻" "🎃"}}
    {{$point := randInt 300}}
    {{range .Message.Reactions}}
      {{- if and (in $emojis .Emoji.Name) .Me}}
        {{- deleteAllMessageReactions nil $.Message.ID .Emoji.Name}}
        {{- $_ := dbIncr $.User.ID "spooky" $point}}
        {{- sendMessage nil (print $.User.Mention " earned " $point " spooky points...")}}{{return}}
      {{- end -}}
    {{end}}
{{else if eq .Reaction.Emoji.Name "🕷️" "🧛‍♂️" "🧟" "🍬" "🍭" "🍫"}}{{/* Trick or Treat */}}
  {{if $db := (dbGet .User.ID "totCD").Value}}
      {{if ne .Message.ID $db.mID}}{{return}}{{end}}
      {{$resp := (dbGet 0 "hal").Value}}
      {{ if not $resp}}{{return}}{{end}}
      {{$embed := structToSdict (index .Message.Embeds 0)}}
      {{$name := (or .Member.Nick .User.Username)}}
      {{if eq .Reaction.Emoji.Name $db.treat}}
          {{$points := randInt 500 2001}}
          {{$_ := dbIncr .User.ID "spooky" $points}}
          {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.treat) 0) "``\x60") $name $points)}}
          {{$embed.Del "Footer"}}
          {{editMessage nil $db.mID (cembed $embed)}}
          {{deleteAllMessageReactions nil $db.mID}}{{return}}
      {{else if eq .Reaction.Emoji.Name $db.trick}}
          {{$tricks := (cslice "points" "mute" "points" "mirror" "points" "mute" "points")}}
          {{$reward := index (shuffle $tricks) 0}}
          {{$embed.Del "Footer"}}
          {{if eq $reward "mute"}}
              {{$points := randInt -1000 0}}
              {{$time := randInt 1 11}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.negTrickMute) 0) "``\x60") $name $time (mult -1 $points))}}
              {{$shh := dbIncr .User.ID "spooky" $points}}
              {{try}}{{$_ := execAdmin "timeout" .User.ID (print $time "m") "🎃Got tricked🎃"}}{{catch}}{{$_ := dbIncr $.User.ID "spooky" -500}}{{print "...can't timeout you, so removed more 500 points."}}{{end}}
          {{else if eq $reward "points"}}
              {{if eq (toInt (randInt 2)) 1}}
                  {{$points := (randInt 0 10000)}}
                  {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.posTrick) 0) "``\x60") $name $points)}}
                  {{$_ := dbIncr .User.ID "spooky" $points}}
              {{else}}
                  {{$points := (randInt -5000 0)}}
                  {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.negTrick) 0) "``\x60") $name (mult -1 $points))}}
                  {{$_ := dbIncr .User.ID "spooky" $points}}
              {{end}}
          {{else if eq  $reward "mirror"}}
            {{$point := or (dbGet .User.ID "spooky").Value 0}}
            {{$rand := randInt 11 | toInt}}
            {{if eq $rand 0 1 2 3}}{{/* reverse */}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickInv) 0) "``\x60") $name)}}
              {{dbSet .User.ID "spooky" (mult -1 $point)}}
            {{else if eq $rand 4 5 6}}{{/* double */}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickDouble) 0) "``\x60") $name)}}
              {{dbSet .User.ID "spooky" (mult 2 $point)}}
            {{else if eq $rand 7 8}}{{/* half */}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickHalf) 0) "``\x60") $name)}}
              {{dbSet .User.ID "spooky" (mult 0.5 $point | toInt)}}
            {{else if eq $rand 9}}{{/* reset */}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickReset) 0) "``\x60") $name)}}
              {{dbSet .User.ID "spooky" 0}}
            {{else if eq $rand 10}}
              {{$embed.Set "description" (printf (print "``\x60\n" (index (shuffle $resp.trickNothing) 0) "``\x60") $name)}}
            {{end}}
          {{end}}
          {{editMessage nil $db.mID (cembed $embed)}}
          {{deleteAllMessageReactions nil $db.mID}}{{return}}
      {{end}}
  {{end}}
{{end}}
