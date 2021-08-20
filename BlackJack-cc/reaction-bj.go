{{ if .ReactionMessage.Embeds }}
    {{ if and ( $data := (dbGet .User.ID "bj").Value ) (in (((index .Message.Embeds 0).Footer.Text)) (str .User.ID)) (eq .Message.ID (toInt $data.msg_id)) }}
        {{ $embed := structToSdict (index .Message.Embeds 0) }}
        {{ $deck := $data.deck }}
        {{ $emojis := $data.emojis }}
        {{ $msg := (toInt $data.msg_id) }}
        {{ $p_cards := $data.p_cards }}
        {{ $d_cards := $data.d_cards }}
        {{ $p_total := $data.p_total }}
        {{ $p_score := 0 }}
        {{ $d_total := $data.d_total}}
        {{  $d_score := 0 }}
        {{ $p_t := $data.p_t }}
        {{ $p_b := $data.p_b }}
        {{ $d_t := $data.d_t }}
        {{ $d_b := $data.d_b }}
        {{ $d_hb := $data.d_hb }}
        {{ $d_ht := $data.d_ht }}
        {{ $score := $data.score }}
        {{ $card := "" }}
        {{ if eq .Reaction.Emoji.ID 874954948801073163 }}
            {{ $card = index $deck 0 }}
            {{ $p_cards = $p_cards.Append $card }}
            {{ $deck = slice $deck 1 }}
            {{ $temp := index ( split $card " " ) 1 }}
            {{ if and (eq $temp "ace") ( lt $p_total 11) }}
                {{ $p_score = 11 }}
            {{ else }}
                {{ $p_score = toInt ( $score.Get $temp ) }}
            {{ end }}
            {{ $p_total = add $p_total $p_score }}
            {{ if reFind `spade|club` (index (split $card " ") 0) }}
                {{ $p_t = $p_t.Append ($emojis.Get (joinStr "" "b" (index (split $card " ") 1))) }}
                {{ $p_b = $p_b.Append ($emojis.Get (index (split $card " ") 0)) }}
            {{ else if reFind `heart|diamond` (index (split $card " ") 0) }}
                {{ $p_t = $p_t.Append ($emojis.Get (joinStr "" "r" (index (split $card " ") 1))) }}
                {{ $p_b = $p_b.Append ($emojis.Get (index (split $card " ") 0)) }}
            {{end}}
            {{ deleteMessageReaction nil .Message.ID .User.ID "hit:874954948801073163" }}
            {{ $embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal: ??" .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_ht.StringSlice) (joinStr " " $d_hb.StringSlice) ) }}
            {{ dbSetExpire .User.ID "bj" (sdict "deck" $deck "p_cards" $p_cards "d_cards" $d_cards "p_total" $p_total "d_total" $d_total "score" $score "p_t" $p_t "p_b" $p_b "d_t" $d_t "d_b" $d_b "d_ht" $d_ht "d_hb" $d_hb "emojis" $emojis "msg_id" (str $msg)) 180 }}
            {{ if gt $p_total 21 }}
                {{ $embed.Set "color" 0xFF0000 }}
                {{ $embed.Set "title" "You Busted" }}
                {{ deleteAllMessageReactions nil .Message.ID }}
                {{ $embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal:  %d " .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_t.StringSlice) (joinStr " " $d_b.StringSlice) $d_total) }}
                {{ dbDel .User.ID "bj" }}
            {{ end }}
        {{ else if eq .Reaction.Emoji.ID 874954815736807454 }}
            {{ range seq 0 13 }} {{/* I dunno why I did this lol*/}}
                {{- if lt $d_total 17 -}}
                    {{ $card = index $deck 0 }}
                    {{- $d_cards = $d_cards.Append $card -}}
                    {{- $deck = slice $deck 1 -}}
                    {{- $temp := index ( split $card " " ) 1 -}}
                    {{- if and (eq $temp "ace") ( le $d_total 11 ) -}}
                        {{- $d_score = 11 -}}
                    {{- else -}}
                        {{- $d_score = toInt ( $score.Get $temp ) -}}
                    {{- end -}}
                    {{- $d_total = add $d_total $d_score -}}
                {{- end -}}
            {{- end -}}
            {{ if reFind `spade|club` (index (split $card " ") 0) }}
                {{ $d_t = $d_t.Append ($emojis.Get (joinStr "" "b" (index (split $card " ") 1))) }}
                {{ $d_b = $d_b.Append ($emojis.Get (index (split $card " ") 0)) }}
            {{ else if reFind `heart|diamond` (index (split $card " ") 0) }}
                {{ $d_t = $d_t.Append ($emojis.Get (joinStr "" "r" (index (split $card " ") 1))) }}
                {{ $d_b = $d_b.Append ($emojis.Get (index (split $card " ") 0)) }}
            {{ end }}
            {{ deleteMessageReaction nil .Message.ID .User.ID "stay:874954815736807454" }}
            {{ if gt $d_total 21 }}
                {{ $embed.Set "color" 0x00FF00 }}
                {{ $embed.Set "title" "Dealer Busted" }}
            {{ else }}
                {{ if gt $p_total $d_total }}
                    {{ $embed.Set "color" 0x00FF00 }} 
                    {{ $embed.Set "title" "You Won!" }}
                {{ else if lt $p_total $d_total }}
                    {{ $embed.Set "color" 0xFF0000 }}
                    {{ $embed.Set "title" "You Lost!" }}
                {{ else if eq $p_total $d_total }}
                    {{ $embed.Set "color" 0xFFFFFF }}
                    {{ $embed.Set "title" "It's a Tie!" }}
                {{ end }}
            {{ end }}
            {{ $embed.Set "description" (printf "%s's Hand:\n%s\n%s\nTotal: %d\n\nDealer's Hand:\n%s\n%s\nTotal:  %d " .User.String (joinStr " " $p_t.StringSlice) (joinStr " " $p_b.StringSlice) $p_total (joinStr " " $d_t.StringSlice) (joinStr " " $d_b.StringSlice) $d_total) }}
            {{ deleteAllMessageReactions nil .Message.ID }}
            {{ dbDel .User.ID "bj" }}
        {{ end }}
        {{ editMessage nil .Message.ID (cembed $embed) }}
    {{ end }}
{{ end }}
