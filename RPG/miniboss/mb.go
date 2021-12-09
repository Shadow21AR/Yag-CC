{{$join := ############### }} {{/* <-- replace ##### with Miniboss join channel ID */}}
{{$mb := ############### }} {{/* <-- replace ##### with Minoboss channel ID */}}
{{$mod := &&&&&&&&&&&&&&&&  }} {{/* <-- replace &&&&& with mode role ID */}}
{{$mbRole := &&&&&&&&&&&&&&&& }} {{/* <-- replace &&&&& with role ID that unlocks #miniboss channel */}}

{{$expiryTime := 10}} {{/* time in MINUTES to reset arena list after being inactive */}}
{{$skull := "💀"}}
{{$crown := "👑"}}

{{/* ----- don't edit if u don't know what you doing -------*/}}
{{/* Copyright (c): Shadow21A, 2021
     License: MIT
     Repository: https://github.com/Shadow21AR/Yag-CC
*/}}
{{if not .ExecData}}
{{deleteTrigger 1}}{{deleteResponce 1}}
	{{$mblist := ""}}{{$count := 1}}{{$topUser := or (toInt (dbGet .Channel.ID "mblist").Value.mbhost) 0}}{{$emoji := ""}}{{$msg := ""}}
	{{$list := or (dbGet .Channel.ID "mblist").Value.mblist dict}}
	{{$ex := or (and (reFind "a_" .Guild.Icon) "gif" ) "png" }}
	{{$icon := print "https://cdn.discordapp.com/icons/" .Guild.ID "/" .Guild.Icon "." $ex "?size=1024" }}
	{{$helpM := "```\n• mb join L#  : To join the list\n• mb leave    : To leave the list\n• mb list     : To view the list```"}}
	{{$embed := sdict "author" (sdict "name" (print .Guild.Name) "icon_url" $icon) "timestamp" currentTime }}

	{{if and .CmdArgs (eq $join .Channel.ID)}}
		{{$cmd := index .CmdArgs 0 | lower}}
		{{if eq $cmd "join"}}
			{{if ge (len .CmdArgs) 2}}
				{{$arg := index .CmdArgs 1}}
				{{if $lvl := reFindAllSubmatches `(?i)\Al(\d+)(?:\s+|\z)` $arg}}
					{{if (not ($list.Get .User.ID))}}
						{{if $msg = (toInt (dbGet .Channel.ID "mblist").Value.mmsg)}}{{deleteMessage nil $msg 1}}{{end}}
						{{$list.Set .User.ID (index $lvl 0 1| toInt)}}
						{{$top := 0}}
						{{range $k, $v := $list}}
							{{- if ge (toInt $v) $top -}}{{- $topUser = $k -}}{{$top = $v -}}{{- end -}}
						{{end}}
						{{range $k, $v := $list}}
							{{- if eq $k $topUser -}}{{$emoji = $crown}}{{else}}{{$emoji = ""}}{{end}}
							{{- $mblist = printf "%s`[%02d]` <@%d> | `L: %d` %s\n" $mblist $count $k $v $emoji -}}
						{{end}}
						{{$embed.Set "title" (print $skull " __Miniboss List [" (len $list) "/10]__ " $skull)}}
						{{$embed.Set "description" (print $mblist "\n" $helpM)}}
						{{$msg = sendMessageRetID nil (cembed $embed)}}
						{{dbSet .Channel.ID "mblist" (sdict "mmsg" (str $msg) "mblist" $list "mbhost" (str $topUser))}}
					{{else}}
						{{deleteMessage nil (sendMessageRetID nil (print .User.Mention " | You are already in list")) 2}}
					{{end}}
				{{scheduleUniqueCC .CCID nil (mult $expiryTime 60) "mblist" (sdict "msg" (str $msg))}}
				{{if eq (len $list) 10}}
					{{$newList := ""}}
					{{range $k, $v := $list}}
						{{giveRoleID $k $mbRole}}
						{{takeRoleID $k $mbRole 180}}
						{{if not (eq $topUser $k)}}
							{{- $newList = printf "%s <@%d>" $newList $k -}}
						{{end}}
					{{end}}
					{{if $msg = (toInt (dbGet .Channel.ID "mblist").Value.mmsg)}}{{deleteMessage nil $msg 1}}{{end}}
					{{dbDel .Channel.ID "mblist"}}
					{{cancelScheduledUniqueCC .CCID "mblist"}}
					{{sendMessage $mb $newList}}
					{{sendMessage $mb (complexMessage "content" (printf "<@%d>" $topUser) "embed" (cembed "description" (printf "```\nRpg miniboss %s```" $newList)))}}
				{{end}}
				{{else}}
					{{deleteMessage nil (sendMessageRetID nil (print .User.Mention " | Use `mb join l#`, where # is your level.")) 2}}
				{{end}}
			{{else}}
				{{deleteMessage nil (sendMessageRetID nil (print .User.Mention " | Use `mb join l#`, where # is your level.")) 2}}
			{{end}}
		{{else if eq $cmd "leave"}}
			{{if $msg = (toInt (dbGet .Channel.ID "mblist").Value.mmsg)}}{{deleteMessage nil $msg 1}}{{end}}
			{{$list.Del .User.ID}}
			{{$top := 0}}
			{{range $k, $v := $list}}
				{{- if ge (toInt $v) $top -}}{{- $topUser = $k -}}{{$top = $v -}}{{- end -}}
			{{end}}
			{{range $k, $v := $list}}
				{{- if eq $k $topUser -}}{{$emoji = $crown}}{{else}}{{$emoji = ""}}{{end}}
				{{- $mblist = printf "%s`[%02d]` <@%d> | `L: %d` %s\n" $mblist $count $k $v $emoji -}}
			{{end}}
			{{$embed.Set "title" (print $skull " __Miniboss List [" (len $list) "/10]__ " $skull)}}
			{{$embed.Set "description" (print $mblist "\n" $helpM)}}
			{{$msg = sendMessageRetID nil (cembed $embed)}}
			{{dbSet .Channel.ID "mblist" (sdict "mmsg" (str $msg) "mblist" $list "mbhost" (str $topUser))}}
			{{scheduleUniqueCC .CCID nil (mult $expiryTime 60) "mblist" (sdict "msg" (str $msg))}}
		{{else if eq $cmd "list"}}
			{{if $msg = (toInt (dbGet .Channel.ID "mblist").Value.mmsg)}}{{deleteMessage nil $msg 1}}{{end}}
			{{$top := 0}}
			{{range $k, $v := $list}}
				{{- if ge (toInt $v) $top -}}{{- $topUser = $k -}}{{$top = $v -}}{{- end -}}
			{{end}}
			{{range $k, $v := $list}}
				{{- if eq $k $topUser -}}{{$emoji = $crown}}{{else}}{{$emoji = ""}}{{end}}
				{{- $mblist = printf "%s`[%02d]` <@%d> | `L: %d` %s\n" $mblist $count $k $v $emoji -}}
			{{end}}
			{{$embed.Set "title" (print $skull " __Miniboss List [" (len $list) "/10]__ " $skull)}}
			{{$embed.Set "description" (print $mblist "\n" $helpM)}}
			{{$msg = sendMessageRetID nil (cembed $embed)}}
			{{dbSet .Channel.ID "mblist" (sdict "mmsg" (str $msg) "mblist" $list "mbhost" (str $topUser))}}
		{{else if eq $cmd "hide"}}
			{{removeRoleID $mbRole}}
		{{else if eq $cmd "reset"}}
			{{if hasRoleID $mod}}
				{{if $msg = (toInt (dbGet .Channel.ID "mblist").Value.mmsg)}}{{deleteMessage nil $msg 1}}{{end}}
				{{dbDel .Channel.ID "mblist"}}
				{{deleteMessage nil (sendMessageRetID nil "Deleted the list!") 5}}
				{{cancelScheduledUniqueCC .CCID "mblist"}}
			{{else}}
				{{deleteMessage nil (sendMessageRetID nil "You don't have permissions to reset list!") 5}}
			{{end}}
		{{end}}
	{{end}}
{{else}}
	{{deleteMessage nil .ExecData.msg 1}}
	{{dbDel .Channel.ID "mblist"}}
	{{deleteMessage nil (sendMessageRetID nil (print "Arena got reset due to inactivity!\nNo player joined the list for last " $expiryTime " minutes.")) 30}}
{{end}}
