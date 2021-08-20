{{ if not .ExecData }}
    {{ if $db := (dbGet .User.ID "bj") }}
        {{ sendMessage nil (printf "%s | Please finish your previous game.\nCan't find it??\nHere: %s" .User.Mention (getMessage $db.Value.channel_id $db.Value.msg_id).Link ) }}
    {{ else }}
        {{ $p_cards := cslice }}
        {{ $d_cards := cslice }}
        {{ $deck := cslice }}
        {{ $suit := cslice "spade" "club" "heart" "diamond" }}
        {{ $face := cslice  "ace" 2 3 4 5 6 7 8 9 10 "joker" "queen" "king" }}
        {{ $score := dict "ace" 1 "2" 2 "3" 3 "4" 4 "5" 5 "6" 6 "7" 7 "8" 8 "9" 9 "10" 10 "king" 10 "queen" 10 "joker" 10 }}
        {{ $p_total := 0 }} {{ $p_score := 0 }}
        {{ $d_total := 0 }} {{ $d_score := 0 }}
        {{/* Emojis */}}
        {{ $emojis := dict "spade" "<:espades:874957677577515090>" "heart" "<:ehearts:874957690974126120>" "diamond" "<:ediamonds:874957704962146314>" "club" "<:eclubs:874957717318557706>" "rqueen" "<:rQ:874957256511348826>" "rking" "<:rK:874957294494973973>" "rjoker" "<:rJ:874957308818501705>" "race" "<:rA:874957319623036928>" "r10" "<:r10:874957647646965790>" "r9" "<:r9:874957434903461908>" "r8" "<:r8:874957444382593024>" "r7" "<:r7:874957454440558592>" "r6" "<:r6:874957463835787284>" "r5" "<:r5:874957576079540264>" "r4" "<:r4:874957602835025925>" "r3" "<:r3:874957616432939068>" "r2" "<:r2:874957632585236511>" "bqueen" "<:bQ:874957337704673321>" "bking" "<:bK:874957355949908019>" "bjoker" "<:bJ:874957367551336450>" "bace" "<:blackA:874958863575687188>" "b10" "<:b10:874958052682514433>" "b9" "<:b9:874957839121129482>" "b8" "<:b8:874957850957475870>" "b7" "<:b7:874957860684058715>" "b6" "<:b6:874957874537840650>" "b5" "<:b5:874957947745226762>" "b4" "<:b4:874957964044283924>" "b3" "<:b3:874957975213715457>" "b2" "<:b2:874957987435929620>" "tblank" "<:blankbacktop:874958066699882516>" "bblank" "<:blankbackbot:874958077714108436>" }}
        {{/* Shuffling deck */}}
        {{ $n := 0 }}
        {{ range seq 0 4 }}
            {{- range seq 0 13 }}
                {{- $deck = $deck.Append (print ( index $suit $n ) " " ( index $face .)) -}}
            {{- end }}
            {{- $n = add $n 1 -}}
        {{ end }}
        {{ $deck = shuffle $deck }}
        {{/* Serving 2 cards to Player and Dealer | calculating scores */}}
        {{/* Player */}}
        {{ range seq 0 2 }}
            {{- $card := index $deck 0 -}}
            {{- $p_cards = ($p_cards.Append $card ) -}}
            {{- $deck = slice $deck 1 -}}
            {{- $temp := index (split $card " ") 1 -}}
            {{- if and (eq $temp "ace")  (lt $p_score 11) -}}
                {{- $p_score = 11 -}}
            {{- else -}}
                {{- $p_score = toInt ($score.Get $temp) -}}
            {{ end }}
            {{- $p_total = add $p_score $p_total -}}
        {{ end }}
        {{/* Dealer */}}
        {{ range seq 0 2 }}
            {{- $card := index $deck 0 -}}
            {{- $d_cards = ($d_cards.Append $card ) -}}
            {{- $deck = slice $deck 1 -}}
            {{- $temp := index (split $card " ") 1 -}}
            {{- if and (eq $temp "ace") (lt $d_score 11) -}}
                {{- $d_score = 11 -}}
            {{- else -}}
                {{- $d_score = toInt ($score.Get $temp) -}}
            {{ end }}
                {{- $d_total = add $d_score $d_total -}}
        {{ end }}
        {{/* Getting equivalent emojis */}}
        {{ $p_t := cslice }} {{ $p_b := cslice }} {{ $d_t := cslice }} {{ $d_b := cslice }} {{ $p_score := "" }}
        {{ range $p_cards }}
            {{- if reFind `spade|club` . -}}
                {{- $p_t = $p_t.Append ($emojis.Get (joinStr "" "b" (index (split . " ") 1 ))) -}}
                {{- $p_b = $p_b.Append ($emojis.Get (index (split . " " ) 0)) -}}
            {{- else if reFind `diamond|heart` . -}}
                {{- $p_t = $p_t.Append ($emojis.Get (joinStr "" "r" (index (split . " ") 1) )) -}}
                {{- $p_b = $p_b.Append ($emojis.Get (index (split . " " ) 0)) -}}
            {{- end -}}
        {{- end -}}
        {{ range $d_cards }}
            {{- if reFind `spade|club` . -}}
                {{- $d_t = $d_t.Append ($emojis.Get (joinStr "" "b" (index (split . " ") 1 ))) -}}
                {{- $d_b = $d_b.Append ($emojis.Get (index (split . " " ) 0)) -}}
            {{- else if reFind `diamond|heart` . -}}
                {{- $d_t = $d_t.Append ($emojis.Get (joinStr "" "r" (index (split . " ") 1) )) -}}
                {{- $d_b = $d_b.Append ($emojis.Get (index (split . " " ) 0)) -}}
            {{- end -}}
        {{- end -}}
        {{ $d_ht := cslice.AppendSlice $d_t }}
        {{ $d_hb := cslice.AppendSlice $d_b }}
        {{ $d_ht.Set 1 ($emojis.Get "tblank") }}
        {{ $d_hb.Set 1 ($emojis.Get "bblank") }}
        {{ $title := "Blackjack" }} {{ $color := 0X0000FF }}
        {{ if eq $p_total 21 }}
            {{ $title = "You Got BLACKJACK!!" }}
            {{ $color = 0x00FF00 }}
        {{ end }}
        {{ $embed := cembed 
        "title" $title
        "color" $color
        "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal:  ??" .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_ht.StringSlice) (joinStr " " $d_hb.StringSlice))
        "thumbnail" (sdict "url" ( .User.AvatarURL "1024" ))
        "footer" (sdict "text" (print "User ID: " .User.ID ))
        "timestamp" currentTime }}
        {{ if lt $p_total 21 }}
            {{ $msg := sendMessageRetID nil $embed }}
            {{ addMessageReactions nil $msg "hit:874954948801073163" "stay:874954815736807454" }}
            {{ dbSetExpire .User.ID "bj" (sdict "deck" $deck "p_cards" $p_cards "d_cards" $d_cards "p_total" $p_total "d_total" $d_total "score" $score "p_t" $p_t "p_b" $p_b "d_t" $d_t "d_b" $d_b "d_ht" $d_ht "d_hb" $d_hb "emojis" $emojis "msg_id" (str $msg ) "channel_id" (str .Channel.ID ) ) 180 }}

            {{ execCC .CCID nil 175 (str $msg) }}
        {{ end }}
    {{ end }}
{{ else }}
    {{ if (dbGet .User.ID "bj") }}
        {{ $msg := toInt .ExecData }}
        {{ $embed := index ( getMessage nil $msg).Embeds 0 | structToSdict }}
        {{ $embed.Set "title" "BlackJack (inactive)" }}
        {{ editMessage nil ( toInt .ExecData ) (cembed $embed ) }}
        {{ deleteAllMessageReactions nil ( toInt .ExecData) }}
        {{ dbDel .User.ID "bj" }}
    {{ end }}
{{end}}
