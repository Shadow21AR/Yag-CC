{{if .ExecData.riddleActive}}
  {{if $msg := getMessage .ExecData.cID .ExecData.mID}}
    {{if not $msg.Embeds}}{{return}}{{end}}
    {{$embed := index $msg.Embeds 0 | structToSdict}}
    {{$embed.Set "Description" "Oh no! Time has run out for the riddle. The answer remains a mysterious secret."}}
    {{$embed.Set "Title" "⌛ Time's Up!"}}
    {{$embed.Set "Footer" (sdict "text" "Stay tuned for the next riddle!")}}
    {{$embed.Set "Color" 0xFF0000}}
    {{editMessage .ExecData.cID .ExecData.mID (cembed $embed)}}
    {{$db := (dbGet .ExecData.uID "riddleCD")}}
    {{$db.Value.Set "active" false}}
    {{dbSetExpire .ExecData.uID "riddleCD" $db (($db.ExpiresAt.Sub currentTime).Seconds | toInt)}}
  {{end}}
{{else}}
  {{$cmd := .Cmd | lower}}
  {{if eq $cmd ";spooky"}}
    {{$user := .Member}}
    {{if .Message.Mentions}}
      {{$user = getMember (index .Message.Mentions 0)}}
    {{end}}
    {{sendMessage nil (cembed 
                       "title" (print "👻 " $user.User.Username "'s spooky point 👻")
                       "description" (print $user.User.Mention " got `" (humanizeThousands (or (dbGet $user.User.ID "spooky").Value 0)) "` spooky points.")
                       "footer" (sdict "text" (print "Requested by " (or .Memebr.Nick .User.Username)))
                       "thumbnail" (sdict "url" (or ($user.AvatarURL "2048") ($user.User.AvatarURL "2048")))
                       "color" 0xFFA500
                      )}}
  {{else if eq $cmd ";treat"}}
    {{if not (hasRoleID 1018470523719655434)}}
  nice try...
      {{deleteResponse 5}}
      {{return}}
    {{end}}
    {{$args := (parseArgs 2 ";treat @user ±points" (carg "member" "target") (carg "int" "spooky points"))}}
    {{$user := $args.Get 0}}
    {{$points := $args.Get 1}}
    {{$shh := dbIncr $user.User.ID "spooky" $points}}
    {{sendMessage nil (print .User.Mention " modified spooky points of " $user.User.Mention " by `" (humanizeThousands $points) "`.")}}
  {{else if eq $cmd ";riddle"}}
    {{$resp := (dbGet 0 "hal").Value}}{{if not $resp}}{{return}}{{end}}
    {{$randomRiddle := index (shuffle $resp.riddles) 0}}
    {{if $cd := (dbGet .User.ID "riddleCD")}}
      {{try}}
        {{print "⚠️ This command is on cooldown, expiring <t:" $cd.ExpiresAt.Unix ":R>, If you haven't picked it, try it [here](<" (getMessage $cd.Value.cID $cd.Value.mID).Link ">)."}}
      {{catch}}
        {{print "⚠️ This command is on cooldown, expiring <t:" $cd.ExpiresAt.Unix ":R>"}}
      {{end}}
      {{return}}
    {{end}}
    {{$embed := cembed
      "title" "🤔 Riddle Time!"
      "description" (print "Can you solve this mysterious riddle?\n\n**Riddle:** " $randomRiddle.riddle)
      "thumbnail" (sdict "url" (or (.Member.AvatarURL "2048") (.User.AvatarURL "2048")))
      "color" 0xFF5733
      "footer" (sdict "text" "⏳ 3 min | reply to this message with your answer using the command: ;ans your_answer")}}
	{{$mID := sendMessageNoEscapeRetID nil (complexMessage "content" .User.Mention "embed" $embed)}}
    {{dbSetExpire .User.ID "riddleCD" (sdict "cID" .Channel.ID "mID" $mID "riddle" $randomRiddle "active" true) 1800}}
    {{scheduleUniqueCC .CCID nil 180 (print .User.ID "riddle") (sdict "cID" .Channel.ID "mID" $mID "uID" .User.ID "riddle" $randomRiddle "riddleActive" true)}}
  {{else if eq $cmd ";ans" ";answer"}}
    {{if $cd := (dbGet .User.ID "riddleCD")}}
		{{if not $cd.Value.active}}{{return}}{{end}}
		{{$ans := $cd.Value.riddle.ans | lower}} 
        {{if not .CmdArgs}}{{return}}{{end}}
        {{$guess := index .CmdArgs 0 | lower}}
		{{$embed := cembed}}
        {{if eq $guess $ans}}
          {{$embed = cembed 
            "title" "🎉 Correct Answer!" 
            "description" (print "Congratulations! You've solved the riddle!\n\n**Answer:** " $cd.Value.riddle.ans) 
            "color" 0x00FF00 
            "thumbnail" (sdict "url" (or (.Member.AvatarURL "2048") (.User.AvatarURL "2048")))
            "footer" (sdict "text" "Well done! Stay tuned for more riddles.")}}
        {{else}}
          {{$embed = cembed 
            "title" "❌ Incorrect Answer"
            "description" (print "Oops! Your answer is incorrect. Don't worry, riddles can be tricky. Keep trying!") 
            "color" 0xFF0000 
            "thumbnail" (sdict "url" (or (.Member.AvatarURL "2048") (.User.AvatarURL "2048")))
            "footer" (sdict "text" "Better luck next time! Stay tuned for more riddles.")}}
        {{end}}
		{{deleteMessage nil $cd.Value.mID 1}}
        {{sendMessage nil (complexMessage "embed" $embed "reply" .Message.ID)}}
        {{cancelScheduledUniqueCC .CCID (print .User.ID "riddle")}}
        {{$cd.Value.Set "active" false}}
        {{dbSetExpire .User.ID "riddleCD" $cd (($cd.ExpiresAt.Sub currentTime).Seconds | toInt)}}
	{{end}}
  {{end}}
{{end}}
