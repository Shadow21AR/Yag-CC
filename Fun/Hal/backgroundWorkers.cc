CC 95:
{{$channel := 997263718826123354}}
{{$items := cslice "xp_points" "xp_boost1" "xp_boost2" "xp_boost3" "xp_boost4" "xp_boost5" "xp_boost6" "boss_bait" "reversal_card" "trick_card" "treat_card"}}
{{if $db := (dbGet $channel "boss").Value}}
	{{$result := ""}}
	{{$reward := dict}}
	{{$users := or (dbGet $channel "bossList").Value sdict}}
	{{range $k, $v := $users}}
		{{if eq $k "545927740629712928"}}
			{{$pointA := randInt 5000}}{{$pointB := randInt 1000}}
			{{$result = printf "%s- <@%s> - got %d (+ %d) points...\n" $result $k $pointA $pointB}}
			{{$reward.Set (str $k)  (add $pointA $pointB)}}
		{{else if eq $k "287796413893705731"}}
			{{$pointA := randInt 5000}}{{$pointB := randInt 500}}
			{{$result = printf "%s- <@%s> - got %d (+ %d) points...\n" $result $k $pointA $pointB}}
			{{$reward.Set (str $k) (add $pointA $pointB)}}
		{{else}}
			{{$pointA := randInt 5000}}
			{{$result = printf "%s- <@%s> - got %d points...\n" $result $k $pointA}}
			{{$reward.Set (str $k) $pointA}}
		{{end}}
        {{if eq (randInt 100 | toInt) 0 1 2 3 4 5 6 7 8 9}}
		  {{$drop := index (shuffle $items) 0}}
          {{$result = printf "%s⤷ and a rare 🎁 `%s`.\n" $result $drop}}
		  {{$reward.Set (print $k "_drop") $drop}}
        {{end}}
	{{else}}
		{{$result = "wait.... no one participated :("}}
	{{end}}
	{{$embeds := (getMessage $channel $db.mID).Embeds}}
	{{if not $embeds}}{{return}}{{end}}
	{{$embed := index $embeds 0 | structToSdict}}
	{{$embed.Set "Description" (print "🎉 Bravo, brave souls! You have triumphed over the spectral adversary and emerged victorious in the Halloween showdown. The echoes of your courage resonate through the haunted realm.\n\n🌟 Claim your well-deserved spoils, and may the spirit of Halloween continue to guide your journey! 🎃✨\n\n" $result)}}
	{{$embed.Del "Footer"}}
	{{editMessage $channel $db.mID (cembed $embed)}}
	{{deleteAllMessageReactions $channel $db.mID}}
	{{dbDel $channel "boss"}}
	{{execCC 96 $channel 1 $reward}}
	{{dbDel $channel "bossList"}}
{{end}}

CC 96:
{{try}}
    {{if .ExecData}}
        {{$list := .ExecData}}{{$c := 0}}
        {{if le (len $list) 0}}{{return}}{{end}}
        {{range $k, $v := $list}}
			{{- if reFind `_drop` $k}}
				{{- $user := index (split $k "_") 0 | toInt64}}
				{{- $inv := (dbGet $user "inv").Value}}
				{{- $inv.Set $v (add ($inv.Get $v) 1)}}
				{{- dbSet $user "inv" $inv}}
			{{- else}}
                {{- $shh := dbIncr (toInt64 $k) "spooky" $v}}
			{{- end}}
			{{- $list.Del $k}}
            {{- $c = add $c 1}}
            {{- if eq $c 10}}{{- break}}{{- end -}}
        {{end}}
        {{execCC .CCID (index (shuffle .Guild.Channels) 0).ID 1 $list}}
    {{end}}	
{{catch}}
	{{.Error}}
{{end}}
