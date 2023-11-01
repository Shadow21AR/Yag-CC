{{if eq (lower .Cmd) ";haunt"}}
{{if $cd := dbGet .User.ID "hauntCD"}}
⚠️ This command is on cooldown, expiring <t:{{ $cd.ExpiresAt.Unix }}:R>{{return}}
{{else}}
  {{$user := .User}}
  {{if .Message.Mentions}}
    {{$user = (index .Message.Mentions 0)}}
  {{end}}
  {{$result := randInt 3}}
  {{$points := randInt 1 1000}}
  {{$print := print ""}}
  {{$resp := (dbGet 0 "hal").Value}}
  {{if not $resp}} something went wrong... {{return}}{{end}}
  {{if eq .User.ID $user.ID}}
	{{if eq 0 (randInt 2)}}
	    {{$print = printf "👻 In the eerie solitude of the spectral realm, behold! %s, driven by an insatiable curiosity, attempted to conjure a haunting upon themselves. The shadows stirred with anticipation, but alas, no spectral revelation unfolded. A tale of self-ghosting, where the darkness echoes with the silence of a ghostly whim." .User.Mention}}
	{{else}}
		{{$print = printf (print "%[1]s" (index (shuffle $resp.haunt.self_win) 0) "\n\nwon %[3]d points") $print .User.Mention $points}}
		{{$shh := dbIncr .User.ID "spooky" $points}}
	{{end}}
  {{else if eq $result 0}}{{/*win*/}}
	{{$print = printf (print "%[1]s" (index (shuffle $resp.haunt.win) 0) "\n\nwon %[4]d points...") $print .User.Mention $user.Mention $points}}
    {{/*$print = print $print "\n\n" $user.Mention " got scared 👻 and lost " $points "..\n\n" .User.Mention " earned " $points " spooky points..."*/}}
    {{$shh := dbIncr .User.ID "spooky" $points}}
    {{$shh := dbIncr $user.ID "spooky" (mult -1 $points)}}
  {{else if eq $result 1}}{{/*lose*/}}
   {{$print = printf (print "%[1]s" (index (shuffle $resp.haunt.lose) 0) "\n\nlost %[4]d points...") $print .User.Mention $user.Mention $points}}
    {{/*$print = print $print "\n\n" .User.Mention " scared themself 💀 and lost " $points "..\n\n" $user.Mention " earned " $points " spooky points..."*/}}
    {{$shh := dbIncr .User.ID "spooky" (mult -1 $points)}}
    {{$shh := dbIncr $user.ID "spooky" $points}}
  {{else}}{{/*draw*/}}
	{{if eq 0 (randInt 2 | toInt)}}
      {{$print = printf (print "%[1]s" (index (shuffle $resp.haunt.draw) 0) "\n\nboth lost %[4]d points...") $print .User.Mention $user.Mention $points}}
      {{$shh := dbIncr .User.ID "spooky" (mult -1 $points)}}
      {{$shh := dbIncr $user.ID "spooky" (mult -1 $points)}}
	{{else}}
      {{$print = printf (print "%[1]s" (index (shuffle $resp.haunt.draw_win) 0) "\n\nboth won %[4]d points...") $print .User.Mention $user.Mention $points}}
      {{$shh := dbIncr .User.ID "spooky" $points}}
      {{$shh := dbIncr $user.ID "spooky" $points}}
{{end}}
  {{end}}
  {{sendMessage nil (cembed 
                     "title" "👻 Unveiling the Haunting Drama 👻"
                     "thumbnail" (sdict "url" .Server.IconURL)
                     "color" 0xFFA500
                     "description" $print)}}
  {{dbSetExpire .User.ID "hauntCD" 1 300}}{{return}}
{{end}}
{{else if eq (lower .Cmd) ";tot" ";trickortreat"}}
  {{if $cd := dbGet .User.ID "totCD"}}
    {{try}}
      {{print "⚠️ This command is on cooldown, expiring <t:" $cd.ExpiresAt.Unix ":R>, If you haven't picked it, try it [here](<" (getMessage $cd.Value.cID $cd.Value.mID).Link ">)."}}
    {{catch}}
      {{print "⚠️ This command is on cooldown, expiring <t:" $cd.ExpiresAt.Unix ":R>"}}
    {{end}}{{return}}
  {{else}}
    {{$trick := index (shuffle (cslice "🕷️" "🧛‍♂️" "🧟")) 0}}
    {{$treat := index (shuffle (cslice "🍬" "🍭" "🍫")) 0}}
	{{$mID := sendMessageRetID nil (
      cembed 
      "title" (print $trick " Trick or Treat! " $treat)
      "description" (print "Beyond the virtual door lies a realm of unknowns. Choose your fate wisely and react with the emoji of your destiny:\n\n- " $trick " for the Cryptic Trick\n- " $treat " for the Enchanting Treat")
      "footer" (sdict "text" (print .User.ID " | " (or .Member.Nick .User.Username)))
      "color" 0xFFA500  
      "thumbnail" (sdict "url" (or (.Member.AvatarURL "1024") (.User.AvatarURL "1024"))))}}
    {{addMessageReactions nil $mID $trick $treat}}
    {{dbSetExpire .User.ID "totCD" (sdict "cID" .Channel.ID "mID" $mID "trick" $trick "treat" $treat) 3600}}{{return}}
  {{end}}
{{end}}
