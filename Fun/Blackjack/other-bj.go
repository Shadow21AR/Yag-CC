{{/* Trigger type : regex.
     Trigger : \A(?:\-|<@!?204255221017214977>)\s*(?:bal|setb|setbalance)(?: +|\z) */}}


{{ $args := parseArgs 0 "__To check balance__ : `-bal [@user]Optional`\n__To set balance__: `-setb @user <amount>`" 
 (carg "member" "user") 
 (carg "int" "amount") }}
{{ $user := .User }}
{{ $value := 0 }}
{{ if $args.IsSet 0 }}
 {{ $user = ($args.Get 0).User }}
{{ end }}
{{ if $args.IsSet 1 }}
 {{ $value = $args.Get 1 | toInt }}
{{ end }}
{{ if eq (lower .Cmd) "-bal" }}
 {{ sendMessage nil (print $user.Mention "'s balance is : " (or (toInt (dbGet $user.ID "CREDIT").Value) 0)) }}
{{ else }}
 {{/* Black Wolf's permission checker here ;) */}}
 {{$perms := "Administrator"}}
{{if (in (split (index (split (exec "viewperms") "\n") 2) ", ") $perms)}}
	{{ dbSet $user.ID "CREDIT" $value }}
       {{ sendMessage nil (print "Success!\nUpdated " $user.Mention " balance to " $value "." ) }}
{{else}}
	{{sendMessage nil (print "You can't use this command\nYou need atleast one of these perms: " $perms) }}
{{end}}
{{ end }}
