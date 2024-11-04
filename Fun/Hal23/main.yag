{{if eq 0 (randInt 20 | toInt)}}{{addReactions (index (shuffle (cslice "🎃" "👻" "🦇")) 0)}}{{end}}
{{$hal := (dbGet 0 "hal").Value}}
{{$bossList := cslice "Jack-O'-Lantern King" "Wraith of the Haunted Forest" "Cursed Witch's Brewmaster" "Spectral Reaper of Souls" "Phantom Jester of Tricks" "Bleeding Stone Golem" "Sister of the Veil" "Kaliwing, the Haunted Parrot" "Moonlit Werewolf Alpha" "Sorcerer's Ghostly Apprentice"}}
{{if not $hal.bosses}}{{return}}{{end}}
{{$channel := 997263718826123354}}
{{if eq 0 (randInt 45 | toInt)}}
	{{if (dbGet 0 "halMob")}}{{return}}{{end}}
	{{$mob := index (shuffle $hal.mobs) 0}}
	{{$messageID := sendMessageRetID $channel (cembed "title" (printf "👻 A wild %s appeared!" $mob.name) "description" (printf "Beware, brave adventurer! The spectral realm stirs as a mysterious presence materializes. A %s emerges from the shadows, ready to challenge your courage.\n\n%s\n\n Approach with caution and prepare for a spectral encounter! ⚔️ Fight it to earn spooky points!" $mob.name $mob.desc) "thumbnail" (sdict "url" $mob.url) "color" 0x9932CC "footer" (sdict "text" "Spectral Encounter"))}}
	{{addMessageReactions $channel $messageID "⚔️"}}
	{{dbSetExpire 0 "halMob" 1 300}}
{{end}}
{{if eq 0 (randInt 75 | toInt)}}
	{{$boss := index (shuffle $bossList) 0}}
    {{if not (dbGet $channel "boss")}}
    {{$mID := sendMessageNoEscapeRetID $channel (complexMessage 
                                               "content" "👻 Attention <@&1164215848714649622>! \nThe spectral realm stirs with activity. A new Halloween boss has appeared! 🎃🌙" 
                                               "embed" (cembed 
                                                        "title" $boss
                                                        "description" ($hal.bosses.Get $boss).desc
                                                        "thumbnail" (sdict "url" ($hal.bosses.Get $boss).url)
                                                        "timestamp" currentTime
                                                        "footer" (sdict "text" (print "⏳ 60 seconds | react 🔔 to get/remove the ping role."))
                                                       ))}}
    {{addMessageReactions $channel $mID "⚔️" "🔔"}}
    {{dbSetExpire $channel "boss" (sdict "boss" $boss "mID" $mID) 600}}
	{{execCC 95 nil 60 true}}
    {{end}}
{{end}}
