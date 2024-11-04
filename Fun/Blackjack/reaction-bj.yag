{{/* trigger type : Reaction - Added reaction only */}}

{{if not .ReactionMessage.Embeds}}{{return}}{{end}}
{{if and ( $data := (dbGet .User.ID "bj").Value ) (in (((index .Message.Embeds 0).Footer.Text)) (str .User.ID)) (eq .Message.ID (toInt $data.msg_id))}}
    {{$embed := structToSdict (index .Message.Embeds 0)}}
    {{$deck := $data.deck}}{{$amount := $data.amount}}{{$emojis := $data.emojis}}{{$msg := (toInt $data.msg_id)}}{{$p_cards := $data.p_cards}}{{$d_cards := $data.d_cards}}{{$p_total := $data.p_total}}{{$p_score := 0}}{{$d_total := $data.d_total}}{{$d_score := 0}}{{$p_t := $data.p_t}}{{$p_b := $data.p_b}}{{$d_t := $data.d_t}}{{$d_b := $data.d_b}}{{$d_hb := $data.d_hb}}{{$d_ht := $data.d_ht}}{{$score := $data.score}}{{$card := ""}}
    {{$col := sdict "spade" "b" "club" "b" "heart" "r" "diamond" "r"}}
    {{if eq .Reaction.Emoji.ID 874954948801073163}}{{/*HIT*/}}
        {{$card = index $deck 0}}
        {{$p_cards = $p_cards.Append $card}}
        {{$deck = slice $deck 1}}
        {{$temp :=split $card " "}}
        {{if and (eq (index $temp 1) "ace") ( lt $p_total 11)}}{{$p_score = 11}}{{else}}{{$p_score = toInt ($score.Get (index $temp 1) )}}{{end}}
        {{$p_total = add $p_total $p_score}}
        {{- $p_t = $p_t.Append ($emojis.Get (print ($col.Get (index $temp 0)) (index $temp 1 ))) -}}
        {{- $p_b = $p_b.Append ($emojis.Get (index $temp 0)) -}}
        {{deleteMessageReaction nil .Message.ID .User.ID "hit:874954948801073163"}}
        {{$embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal: ??" .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_ht.StringSlice) (joinStr " " $d_hb.StringSlice) )}}
        {{dbSetExpire .User.ID "bj" (sdict "amount" $amount "deck" $deck "p_cards" $p_cards "d_cards" $d_cards "p_total" $p_total "d_total" $d_total "score" $score "p_t" $p_t "p_b" $p_b "d_t" $d_t "d_b" $d_b "d_ht" $d_ht "d_hb" $d_hb "emojis" $emojis "msg_id" (str $msg)) 180}}
        {{scheduleUniqueCC .CCID nil 175 (print .User.ID "bj") (sdict "msg" (str $msg) "amt" $amount)}}
        {{if gt $p_total 21}}
            {{$embed.Set "color" 0xFF0000}}
            {{$embed.Set "title" "You Busted"}}
            {{deleteAllMessageReactions nil .Message.ID}}
            {{$embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal:  %d \n\nYou lost `%d` Credits." .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_t.StringSlice) (joinStr " " $d_b.StringSlice) $d_total $amount)}}
            {{$notNice := dbIncr .User.ID "CREDITS" (mult $amount -1)}}
            {{dbDel .User.ID "bj"}}
            {{cancelScheduledUniqueCC .CCID (print .User.ID "bj")}}
        {{end}}
    {{else if eq .Reaction.Emoji.ID 874954815736807454}}{{/*STAY*/}}
        {{range seq 0 13}} {{/* I dunno how many potential cards dealer can draw, so just using 13*/}}
            {{- if le $d_total 17 -}}{{/* Dealer must stop drawing if its card exceeds 17 or more*/}}
                {{- $card = index $deck 0}}
                {{- $d_cards = $d_cards.Append $card -}}
                {{- $deck = slice $deck 1 -}}
                {{- $temp := split $card " "}}
                {{- if and (eq (index $temp 1) "ace") ( le $d_total 11 ) -}}{{- $d_score = 11 -}}{{- else -}}{{- $d_score = toInt ($score.Get (index $temp 1)) -}}{{- end -}}
                {{- $d_total = add $d_total $d_score -}}
                {{- $d_t = $d_t.Append ($emojis.Get (print ($col.Get (index $temp 0)) (index $temp 1))) -}}
                {{- $d_b = $d_b.Append ($emojis.Get (index $temp 0)) -}}
            {{- end -}}
        {{- end -}}
        {{deleteMessageReaction nil .Message.ID .User.ID "stay:874954815736807454"}}
        {{if gt $d_total 21}}
            {{$embed.Set "color" 0x00FF00}}
            {{$embed.Set "title" "Dealer Busted"}}
            {{$embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal:  %d\n\nYou won `%d` Credits." .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_t.StringSlice) (joinStr " " $d_b.StringSlice) $d_total $amount)}}
            {{$nice := dbIncr .User.ID "CREDITS" (mult 2 $amount)}}
        {{else}}
            {{if gt $p_total $d_total}}
                {{$embed.Set "color" 0x00FF00}} 
                {{$embed.Set "title" "You Won!"}}
                {{$embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal:  %d\n\nYou won `%d` Credits." .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_t.StringSlice) (joinStr " " $d_b.StringSlice) $d_total $amount)}}
                {{$nice := dbIncr .User.ID "CREDITS" (mult 2 $amount)}}
            {{else if lt $p_total $d_total}}
                {{$embed.Set "color" 0xFF0000}}
                {{$embed.Set "title" "You Lost!"}}
                {{$embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal:  %d\n\nYou Lost `%d` Credits." .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_t.StringSlice) (joinStr " " $d_b.StringSlice) $d_total $amount)}}
                {{$nice := dbIncr .User.ID "CREDITS" (mult $amount -1)}}
            {{else if eq $p_total $d_total}}
                {{$embed.Set "color" 0xFFFFFF}}
                {{$embed.Set "title" "It's a Tie!"}}
                {{$embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal:  %d\n\nNobody won anything lol" .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_t.StringSlice) (joinStr " " $d_b.StringSlice) $d_total)}}
            {{end}}
        {{end}}
        {{deleteAllMessageReactions nil .Message.ID}}
        {{dbDel .User.ID "bj"}}
        {{cancelScheduledUniqueCC .CCID (print .User.ID "bj")}}
    {{end}}
    {{editMessage nil .Message.ID (cembed $embed)}}
{{end}}
