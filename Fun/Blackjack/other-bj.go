{{/* Trigger type : regex.
     Trigger : \A(?:\-|<@!?204255221017214977>)\s*(?:bal|setb|giveb)(?:\s+|\z) */}}

{{ $args := parseArgs 0 "__To check balance__ : `-bal [@user]Optional`\n__To set balance__: `-setb @user <amount>`\n__To add balance__: `-giveb @user <amount>`" 
	(carg "member" "user") 
	(carg "int" "amount") }}
 {{$perms := "Administrator"}}
{{ $user := .User }}
{{ $value := 0 }}
{{ if $args.IsSet 0 }}
	{{ $user = ($args.Get 0).User }}
{{ end }}
{{ if $args.IsSet 1 }}
	{{ $value = $args.Get 1 | toInt }}
{{ end }}
{{ if eq (lower .Cmd) "-bal" }}
	{{ sendMessage nil (print $user.Username "'s balance is : " (or (toInt (dbGet $user.ID "CREDIT").Value) 0)) }}
{{ else if eq (lower .Cmd) "-setb" }}
	 {{/* Black Wolf's permission checker here ;) */}}
	{{if (in (split (index (split (exec "viewperms") "\n") 2) ", ") $perms)}}
		{{ dbSet $user.ID "CREDIT" $value }}
		{{ sendMessage nil (print "Success!\nUpdated " $user.Username " balance to " $value "." ) }}
	{{else}}
		{{sendMessage nil (print "You can't use this command\nYou need at least one of these perms: " $perms) }}
	{{end}}
{{ else if eq (lower .Cmd) "-giveb" }}
	 {{/* Black Wolf's permission checker here again ;) */}}
	{{if (in (split (index (split (exec "viewperms") "\n") 2) ", ") $perms)}}
		{{ $new := dbIncr $user.ID "CREDIT" $value }}
		{{ sendMessage nil (print "Success!\nUpdated " $user.Username " balance to " $new "." ) }}
	{{else}}
		{{sendMessage nil (print "You can't use this command\nYou need at least one of these perms: " $perms) }}
	{{end}}
{{ end }}
