{{try}}{{$resp := or (dbGet 0 "hal").Value sdict}}
.... add stuffs
{{dbSet 0 "hal" $resp}}
{{sendMessage 1017388310563401758 (complexMessage "content" (print "file size: " (len (json $resp))) "file" (json $resp true) "filename" "data")}}
{{catch}}{{.Error}}{{end}}

All Availabe data:
{
	"bosses": {
		"Bleeding Stone Golem": {
			"desc": "From the cursed heart of an ancient quarry, the Bleeding Stone Golem emerges. Its towering form is sculpted from stones soaked in the blood of long-forgotten rituals. Crimson veins pulse through its stony limbs, and eerie whispers echo from within. The air around it is heavy with the metallic scent of blood. Beware as it awakens, seeking vengeance from the depths of the spectral quarry.\n\n💔 Witness the awakening of the Bleeding Stone Golem! React with⚔️ to face the sentinel carved from cursed stones.",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1164208542631342140/ScaletheCosmos_human-like_emancipated_monster_with_large_red_cr_73a5b957-c3f4-4d4a-a116-a2d77ea30807.png"
		},
		"Cursed Witch's Brewmaster": {
			"desc": "A wicked witch who brews potions of chaos and mischief. Beware of her magical concoctions and unpredictable spells.\n\n🧙 The Cursed Witch's Brewmaster is stirring up trouble! React with ⚔️ to challenge the magical menace.",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1164207559499063367/2Q.png"
		},
		"Jack-O'-Lantern King": {
			"desc": "The spectral ruler of pumpkins and mischief. This boss has a wicked grin and commands an army of mischievous pumpkin minions.\n\n🎃 The Jack-O'-Lantern King has emerged from the shadows! React with ⚔️ to challenge the pumpkin monarch.",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1164206813902815302/2Q.png"
		},
		"Kaliwing, the Haunted Parrot": {
			"desc": "Kaliwing, a spectral parrot with feathers as dark as the midnight abyss, emerges from the eerie mist. Its wings carry whispers of ghostly squawks, and its eyes gleam with the mysteries of the afterlife. Known to mimic the haunting calls of forgotten spirits, Kali is a cryptic entity with ties to the very essence of Kaliween. Face the enigmatic parrot in a dance between the worlds, where shadowy feathers cast spells of eerie enchantment.\n\n🦜 Kaliwing, the Haunted Parrot, emerges from the spectral mist! React with ⚔️ to unravel the mysterious squawks woven by the ancient parrot of Halloween.",
			"url": "https://media.discordapp.net/attachments/1017388310563401758/1164208543713480874/ScaletheCosmos_white_parrot_in_prom_suit_realistic_cinematic_li_51b5a205-ce0b-4e98-8b4e-7667666e5104.png"
		},
		"Moonlit Werewolf Alpha": {
			"desc": " massive werewolf with fur as dark as the night sky. Only appearing under the full moon, it leads a pack of fearsome lycanthropes.\n\n🌕 The Moonlit Werewolf Alpha emerges! React with ⚔️ to face the leader of the lycanthropic pack",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1164208216733921340/ScaletheCosmos_wolfman_monster_monstrous_pathfinder_kingmaker_a_69f7cbe3-cf59-477b-861f-2354fc9b00fc.png"
		},
		"Phantom Jester of Tricks": {
			"desc": "A mischievous phantom jester with a penchant for playing tricks on unsuspecting souls. Watch out for its unpredictable antics.\n\n🃏 The Phantom Jester of Tricks is here to play! React with⚔️ to challenge the spectral trickster",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1164208011833790464/Z.png"
		},
		"Sister of the Veil": {
			"desc": "In the haunted corridors of an ethereal chapel, the Sister of the Blackened Veil manifests. A ghostly nun, her face veiled in black, glides with an otherworldly grace. Wisps of black blood trail behind her, staining the spectral ground. Eerie prayers echo through the chapel as her eyes glow with an otherworldly presence. Beware, for the Sister of the Veil seeks penance in the shadows of the haunted chapel.\n\n⚫ Behold the manifestation of the Sister of the Blackened Veil! React with ⚔️ to confront the ghostly nun veiled in darkness",
			"url": "https://media.discordapp.net/attachments/1017388310563401758/1164208543071748216/ScaletheCosmos_peasant_ghoul_screams_ghost_face_black_tears_sta_3f396846-d739-4ade-aac9-cdceba8fd788.png"
		},
		"Sorcerer's Ghostly Apprentice": {
			"desc": "A spectral apprentice to a powerful sorcerer, wielding magical spells and illusions. Beware of its ghostly conjurations.\n\n👻 The Sorcerer's Ghostly Apprentice materializes! React with ⚔️ to challenge the phantom spellcaster.",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1164208748210950224/9k.png"
		},
		"Spectral Reaper of Souls": {
			"desc": "A haunting reaper who roams the spectral plane, collecting lost souls. Its scythe is an embodiment of the Halloween harvest.\n\n💀 The Spectral Reaper of Souls appears! React with ⚔️ to face the embodiment of the Halloween harves",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1164207725580931092/2Q.png"
		},
		"Wraith of the Haunted Forest": {
			"desc": "A ghostly wraith that haunts the depths of a mysterious forest. Its presence is marked by swirling leaves and eerie whispers.\n\n🌲 The Wraith of the Haunted Forest has awakened! React with⚔️ to face the ghostly guardian.",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1164207361628573736/9k.png"
		}
	},
	"haunt": {
		"draw": [
			"👻 Witness the spectral chaos unfold! %s and %s, intertwined in the dance of the unknown, have haunted each other. A symphony of spooks reverberates through the haunted realm!",
			"👻 Double the fright! In the ethereal dance of shadows, %s and %s exchanged ghostly scares, giving rise to a haunted convergence. Spooky points are lost by both in the spectral tango.",
			"👻 Ghostly showdown commences! %s and %s, locked in a spectral duel, both ventured to scare the other. The haunting dance unfolds in a dramatic spectral performance."
		],
		"draw_win": [
			"👻 In a spectral dance of equilibrium, %s and %s intertwine their haunting energies. The result? A harmonious convergence where both spirits triumph, earning %d spooky points each!",
			"👻 Behold the haunting unity! %s and %s, in a mystical exchange, both claim victory in the spectral dance. Spooky points flow to both, creating a symphony of spectral equilibrium.",
			"👻 The spectral forces align! %s and %s, in a ghostly tango, have each earned %d spooky points. The haunted realm echoes with the harmony of dual triumph!"
		],
		"lose": [
			"👻 Alas! %s, in an attempt to weave ghostly fear upon %s, found themselves ensnared in a spectral tapestry of their own creation. A self-ghosting tale unfolds!",
			"👻 A courageous venture to spook %[3]s has twisted into a haunting reflection. The specter of fright now lingers upon %[2]s.",
			"👻 Oh, dear %[2]s! The pursuit to haunt %[3]s has taken an unexpected turn, unveiling a frightful revelation. Ghostly echoes resonate with a tale of unexpected spooks."
		],
		"self_win": [
			"👻 Unveiling a tale of self-ghosting! %s, in a daring venture to spook themselves, has conjured a spectral surprise. Spooky points are earned in this solo dance of haunting!",
			"👻 A haunting reflection! %s, with courage unmatched, successfully spooks themselves. The echoes of their own fright resonate, earning them spooky points. A self-ghosting journey unfolds!",
			"👻 Oh, brave %s! In a twist of spectral fate, the pursuit of self-ghosting has proven successful. earning spooky points in this haunting solo venture!"
		],
		"win": [
			"👻 In the eerie tapestry of the spectral realm, behold! %s has summoned a spine-chilling haunt upon %s. The very air resonates with ghostly fright!",
			"👻 Brave souls, take heed! %s, a harbinger of the supernatural, has bestowed upon %s a hair-raising scare. Darkness converges, and spooky points are claimed.",
			"👻 Tremble, %[3]s! A spectral presence, conjured by %[2]s, sends shivers down the spine in a masterful haunt. Spooky points tremor in the haunting aftermath!"
		]
	},
	"mobs": [
		{
			"desc": "A translucent figure that flickers in and out of existence, the Ghostly Apparition leaves a cold shiver in its wake.",
			"name": "Ghostly Apparition",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165627258275373157/2Q.png"
		},
		{
			"desc": "A wailing spirit with a mournful cry, the Eerie Banshee haunts the shadows, warning of impending doom.",
			"name": "Eerie Banshee",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165627784463388862/9k.png"
		},
		{
			"desc": "A phantom entity that glides silently through the darkness, the Spectral Phantom is a mysterious and ethereal presence.",
			"name": "Spectral Phantom",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165628106174890138/2Q.png"
		},
		{
			"desc": "Formless entities that lurk in the darkness, the Cursed Shadows manifest as elusive and unsettling specters.",
			"name": "Cursed Shadows",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165628277226995763/2Q.png"
		},
		{
			"desc": "A restless spirit that roams the haunted grounds, the Haunted Spirit seeks solace in the afterlife and may appear as a flickering light.",
			"name": "Haunted Spirit",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165628481493794886/9k.png"
		},
		{
			"desc": "A malevolent wraith with a ghastly visage, the Ghastly Wraith is a vengeful spirit that hungers for the souls of the living.",
			"name": "Ghastly Wraith",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165628685878050907/9k.png"
		},
		{
			"desc": "An ephemeral shade that materializes in the moonlight, the Ephemeral Shade embodies the mysteries of the spectral realm.",
			"name": "Ephemeral Shade",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165629134408515594/9k.png"
		},
		{
			"desc": "A cryptic apparition with enigmatic features, the Cryptic Apparition is a ghostly entity that eludes understanding.",
			"name": "Cryptic Apparition",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165629433592434751/9k.png"
		},
		{
			"desc": "A phantom banshee with an otherworldly wail, the Phantom Banshee heralds the arrival of supernatural occurrences.",
			"name": "Phantom Banshee",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165629686257299477/2Q.png"
		},
		{
			"desc": "A shadowy specter that moves stealthily through the night, the Shadowy Specter is a mysterious and haunting presence.",
			"name": "Shadowy Specter",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165629939614220408/2Q.png"
		},
		{
			"desc": "A wraith draped in an aura of despair, the Wraith of Despair emanates an overwhelming sense of sorrow and gloom.",
			"name": "Wraith of Despair",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165630202429309011/Z.png"
		},
		{
			"desc": "A spectral guardian that watches over forbidden realms, the Phantom Guardian appears as a shimmering figure in the moonlight.",
			"name": "Phantom Guardian",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165630456373448864/9k.png"
		},
		{
			"desc": "An ethereal stalker that prowls the spectral landscape, the Ethereal Stalker is an elusive and ghostly presence.",
			"name": "Ethereal Stalker",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165630568411709491/9k.png"
		},
		{
			"desc": "A sorrowful spirit that lingers in the haunted places, the Sorrowful Spirit emanates an aura of melancholy and longing.",
			"name": "Sorrowful Spirit",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165631297402703952/9k.png"
		},
		{
			"desc": "A phantom manifestation with the ability to materialize at will, the Phantom Manifestation is a spectral enigma.",
			"name": "Phantom Manifestation",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165630886235099176/9k.png"
		},
		{
			"desc": "An enigmatic shade that exists at the crossroads between realms, the Enigmatic Shade is a mysterious and elusive entity.",
			"name": "Enigmatic Shade",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165630776193335356/2Q.png"
		},
		{
			"desc": "A spectral illusion that deceives the senses, the Spectral Illusion is a ghostly mirage that confounds and mystifies.",
			"name": "Spectral Illusion",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165631095824461835/2Q.png"
		},
		{
			"desc": "An ethereal apparition that phases in and out of reality, the Ethereal Apparition is a ghostly anomaly.",
			"name": "Ethereal Apparition",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165631747317321768/2Q.png"
		},
		{
			"desc": "A wraith formed from the darkest shadows, the Wraith of Shadows is a malevolent force that thrives in obscurity.",
			"name": "Wraith of Shadows",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165631356328493116/9k.png"
		},
		{
			"desc": "A cursed phantasm that embodies the tormented, the Cursed Phantasm is a spectral entity bound by malevolent forces.",
			"name": "Cursed Phantasm",
			"url": "https://cdn.discordapp.com/attachments/1017388310563401758/1165631597408686100/Z.png"
		}
	],
	"negTrick": [
		"👻 Beware, valiant %s! Alas, the Cryptic Trick reveals its darker side. Shadows dance with mockery, and haunting laughter echoes through the corridors. As illusions ensnare your senses and spectral riddles confound your mind, you've fallen victim. %d points are subtracted from the ghostly ledger, a mark of the trickery that shadows your journey.",
		"👻 Greetings, seeker of mysteries, %s! The Cryptic Trick, ever mischievous, unfolds its illusions with a touch of malevolence. As shadows mock your courage and spectral riddles confound your senses, %d points are deducted from the ghostly ledger. A lesson learned in the dance of shadows.",
		"👻 Oh, daring %s! The Cryptic Trick, a phantom of deceptive whimsy, weaves illusions of darkness around you. Shadows dance with sinister glee, and as you navigate through the unseen game, %d points are subtracted from the ghostly ledger—a price paid for daring the spectral unknown.",
		"👻 Hark, valiant %s! Beyond the virtual door, the Cryptic Trick reveals its trickster nature. Illusions waver with malevolence, and spectral riddles confound your very perception. In your encounter with the unseen game, %d points are deducted from the ghostly ledger, marking the darker path you've tread.",
		"👻 Greetings, seeker of mysteries, %s! The Cryptic Trick, in its mischievous revelry, bestows upon you a haunting memory. As shadows dance with mockery and spectral riddles ensnare your mind, %d points are subtracted from the ghostly ledger. A lesson learned in the dance of shadows and tricks.",
		"👻 Behold, brave %s! Alas, the Cryptic Trick has played its hand, weaving illusions of darkness around you. Shadows mock your courage, and as you navigate through the unseen game, %d points are subtracted from the ghostly ledger—a mark of the trickery that shrouds your journey.",
		"👻 Noble %s, as you reach for the spectral door, the Cryptic Trick reveals its malevolent side. Shadows dance with sinister glee, and spectral riddles ensnare your senses. In your encounter with the unseen game, %d points are deducted from the ghostly ledger—a price paid for daring the spectral unknown.",
		"👻 Greetings, seeker of mysteries, %s! Alas, the Cryptic Trick has chosen a darker path. Illusions waver with malevolence, and spectral riddles confound your very perception. In your encounter with the unseen game, %d points are subtracted from the ghostly ledger, marking the trickery that shadows your journey.",
		"👻 Valiant %s, as you stand before the virtual door, the Cryptic Trick unveils its mischievous nature. Shadows mock your courage, and spectral riddles ensnare your senses. In your encounter with the unseen game, %d points are deducted from the ghostly ledger—a lesson learned in the dance of shadows.",
		"👻 Beware, daring %s! The Cryptic Trick, a phantom of deceptive whimsy, reveals its trickster nature. Shadows dance with sinister glee, and as you navigate through the unseen game, %d points are subtracted from the ghostly ledger. A mark of the darker path chosen in the spectral unknown."
	],
	"negTrickMute": [
		"🔥 Beware, valiant %s! Alas, the Banishing Trick reveals its infernal nature. Shadows warp around you, and with a sinister laughter, you find yourself banished to hell for the %dm.\n\n%d points are subtracted from the ghostly ledger, marking the torment endured in the spectral abyss.",
		"🔥 Greetings, seeker of mysteries, %s! The Banishing Trick, ever malevolent, unfolds its infernal scheme. As shadows mock your courage and spectral laughter echoes, you find yourself banished to hell for the %dm.\n\n%d points are deducted from the ghostly ledger. A lesson learned in the dance of infernal shadows.",
		"🔥 Oh, daring %s! The Banishing Trick, a tormentor of souls, weaves illusions of darkness around you. Shadows dance with sinister glee, and as you navigate through the unseen game, you find yourself banished to hell for the %dm.\n\n%d points are subtracted from the ghostly ledger—a price paid for daring the infernal unknown.",
		"🔥 Hark, valiant %s! Beyond the virtual door, the Banishing Trick reveals its infernal whimsy. Illusions waver with malevolence, and spectral laughter taunts your very existence. In your encounter with the unseen game, you find yourself banished to hell for the %dm.\n\n%d points are deducted from the ghostly ledger, marking the infernal path you've tread.",
		"🔥 Greetings, seeker of mysteries, %s! The Banishing Trick, in its malevolent revelry, bestows upon you an infernal fate. As shadows dance with mockery and spectral laughter ensnares your mind, you find yourself banished to hell for the %dm.\n\n%d points are subtracted from the ghostly ledger. A lesson learned in the dance of infernal shadows.",
		"🔥 Behold, brave %s! Alas, the Banishing Trick has played its infernal hand, weaving illusions of darkness around you. Shadows mock your courage, and as you navigate through the unseen game, you find yourself banished to hell for the %dm.\n\n%d points are subtracted from the ghostly ledger—a mark of the infernal torment that shrouds your journey.",
		"🔥 Noble %s, as you reach for the spectral door, the Banishing Trick reveals its infernal side. Shadows dance with sinister glee, and spectral laughter ensnares your senses. In your encounter with the unseen game, you find yourself banished to hell for the %dm.\n\n%d points are deducted from the ghostly ledger—a price paid for daring the infernal unknown.",
		"🔥 Greetings, seeker of mysteries, %s! Alas, the Banishing Trick has chosen a darker path. Illusions waver with malevolence, and spectral laughter taunts your very existence. In your encounter with the unseen game, you find yourself banished to hell for the %dm.\n\n%d points are subtracted from the ghostly ledger, marking the infernal torment that shadows your journey.",
		"🔥 Valiant %s, as you stand before the virtual door, the Banishing Trick unveils its infernal nature. Shadows mock your courage, and spectral laughter ensnares your senses. In your encounter with the unseen game, you find yourself banished to hell for the %dm.\n\n%d points are deducted from the ghostly ledger—a lesson learned in the dance of infernal shadows.",
		"🔥 Beware, daring %s! The Banishing Trick, a tormentor of souls, reveals its infernal whimsy. Shadows dance with sinister glee, and as you navigate through the unseen game, you find yourself banished to hell for the %dm.\n\n%d points are subtracted from the ghostly ledger. A mark of the infernal path chosen in the spectral unknown."
	],
	"posTrick": [
		"🌟 Rejoice, valiant %s! You stand at the threshold of spectral wonders, and the Positive Trick unveils its radiant magic before you. As ethereal light dances around, a joyous laughter echoes through the corridors. Navigating through uplifting illusions and delightful spectacles, you've emerged triumphant. %d points in the ghostly ledger stand as a testament to your positivity. Well done, adventurer!",
		"🌟 Greetings, seeker of joy, %s! The Positive Trick beckons, a celebration of light and laughter that brightens the very fabric of reality. As you embrace the enchanting illusions and revel in joyous riddles, you've proven your mettle in the unseen game. Points in the ghostly ledger, totaling %d, acknowledge your resilience and courage in this joyful spectral encounter.",
		"🌟 Oh, daring %s! The Positive Trick, a sprite of delightful whimsy, weaves illusions of light around you. Joyful laughter resonates, and as you navigate through the unseen game, %d points are added to the ghostly ledger—a reward for embracing the positivity of the spectral unknown.",
		"🌟 Hark, valiant %s! Beyond the virtual door, the Positive Trick reveals its celebratory nature. Illusions shimmer with joy, and uplifting riddles resonate with positivity. In your encounter with the unseen game, %d points are added to the ghostly ledger, marking the brighter path you've tread.",
		"🌟 Greetings, seeker of joy, %s! The Positive Trick, in its jubilant revelry, bestows upon you a heartwarming memory. As light dances with cheer and joyous riddles uplift your spirit, %d points are added to the ghostly ledger. A lesson learned in the dance of joy and positive tricks.",
		"🌟 Behold, brave %s! Alas, the Positive Trick has played its hand, weaving illusions of light around you. Laughter echoes in celebration, and as you navigate through the unseen game, %d points are added to the ghostly ledger—a mark of the positivity that illuminates your journey.",
		"🌟 Noble %s, as you reach for the spectral door, the Positive Trick reveals its uplifting side. Light dances with joy, and joyous riddles resonate in the air. In your encounter with the unseen game, %d points are added to the ghostly ledger—a reward for embracing the positivity of the spectral unknown.",
		"🌟 Greetings, seeker of joy, %s! Alas, the Positive Trick has chosen a brighter path. Illusions shimmer with light, and joyous riddles resonate in the corridors. In your encounter with the unseen game, %d points are added to the ghostly ledger, marking the positivity that brightens your journey.",
		"🌟 Valiant %s, as you stand before the virtual door, the Positive Trick unveils its jubilant nature. Light dances with cheer, and joyous riddles uplift your spirit. In your encounter with the unseen game, %d points are added to the ghostly ledger—a lesson learned in the dance of joy.",
		"🌟 Rejoice, daring %s! The Positive Trick, a sprite of delightful whimsy, reveals its celebratory nature. Light dances with cheer, and as you navigate through the unseen game, %d points are added to the ghostly ledger. A mark of the brighter path chosen in the spectral unknown."
	],
	"riddles": [
		{
			"ans": "Owl",
			"riddle": "In the moonlit night, I soar without a sound. Silent hunter of the skies, darkness is where I'm found. What am I?"
		},
		{
			"ans": "Shadow",
			"riddle": "A cloak of darkness, a figure in the night. I dwell in shadows, out of sight. What am I?"
		},
		{
			"ans": "Spider",
			"riddle": "With a thousand legs, I crawl and creep. In the haunted corners, my secrets I keep. What am I?"
		},
		{
			"ans": "Candle",
			"riddle": "A spectral glow, a flickering light. In the haunted darkness, I guide the night. What am I?"
		},
		{
			"ans": "Ghost",
			"riddle": "In the graveyard's silence, I echo the past. Tombstones and memories, my realm so vast. What am I?"
		},
		{
			"ans": "Leaves",
			"riddle": "I dance with the wind, a leafy delight. Rustling in the dark, under the moon's soft light. What am I?"
		},
		{
			"ans": "Pumpkin",
			"riddle": "With a wicked grin and eyes so bright, I come alive in the Halloween night. What am I?"
		},
		{
			"ans": "Werewolf",
			"riddle": "A nocturnal hunter, my eyes gleam in the dark. Sharp fangs and a howl, I roam the haunted park. What am I?"
		},
		{
			"ans": "Witch",
			"riddle": "In the witching hour, I brew a magical potion. A cauldron of spells and eerie emotion. What am I?"
		},
		{
			"ans": "Bones",
			"riddle": "I rattle and creak in the midnight air. Haunting the living, causing despair. What am I?"
		},
		{
			"ans": "Bat",
			"riddle": "With wings outspread, I fly in the night. Creatures below tremble at my ghostly sight. What am I?"
		},
		{
			"ans": "Dragon",
			"riddle": "A creature of legend, scales and fire. In the dragon's breath, tales inspire. What am I?"
		},
		{
			"ans": "Spider",
			"riddle": "In the cobweb's embrace, I patiently wait. A venomous bite, sealing one's fate. What am I?"
		},
		{
			"ans": "Ship",
			"riddle": "A haunted vessel, I sail the astral sea. Ghostly whispers and shadows accompany me. What am I?"
		},
		{
			"ans": "Zombie",
			"riddle": "Beneath the graveyard soil, I slumber deep. Rising with the moon, in the night I creep. What am I?"
		},
		{
			"ans": "Ghost",
			"riddle": "In the eerie glow, I cast a spectral spell. An apparition from beyond, where shadows dwell. What am I?"
		},
		{
			"ans": "Willowisp",
			"riddle": "With a lantern in hand, I guide the lost. My spectral glow, a guiding post. What am I?"
		},
		{
			"ans": "Owl",
			"riddle": "A nocturnal creature, my hoots resonate. In the ghostly silence, I determine fate. What am I?"
		},
		{
			"ans": "Vampire",
			"riddle": "A creature of the crypt, in darkness I reside. A bloodsucking fiend with nowhere to hide. What am I?"
		},
		{
			"ans": "Ghost",
			"riddle": "With a ghostly wail, I haunt the hall. A spirit in chains, forever enthralled. What am I?"
		},
		{
			"ans": "Banshee",
			"riddle": "In the moonlit mist, I dance with grace. A creature of elegance in the spectral space. What am I?"
		},
		{
			"ans": "Keeper",
			"riddle": "A ghastly figure with a lantern aglow. In the graveyard's silence, my presence I show. What am I?"
		},
		{
			"ans": "Sentry",
			"riddle": "With a skeletal grin, I guard the gate. An eerie sentinel in the haunted estate. What am I?"
		},
		{
			"ans": "Mirror",
			"riddle": "In the spectral mirror, reflections distort. A phantom image, a shadowy escort. What am I?"
		},
		{
			"ans": "Potion",
			"riddle": "A magical brew, simmering with fright. In the cauldron's depths, I weave the night. What am I?"
		},
		{
			"ans": "Shadow",
			"riddle": "A creature of the shadows, I silently glide. In the night's embrace, where secrets hide. What am I?"
		},
		{
			"ans": "Jester",
			"riddle": "With a ghoulish grin, I rise from the grave. A skeletal jester, here to misbehave. What am I?"
		},
		{
			"ans": "Music",
			"riddle": "A phantom melody in the moonlit air. Echoes of the past, hauntingly rare. What am I?"
		},
		{
			"ans": "Swamp",
			"riddle": "A creature of the mist, elusive and sly. In the haunted swamp, where spirits lie. What am I?"
		},
		{
			"ans": "Spirit",
			"riddle": "With eyes aglow, I haunt the glade. A mythical creature in the moonlit shade. What am I?"
		},
		{
			"ans": "Guardian",
			"riddle": "In the crypt's embrace, I rise with dread. A skeletal warrior, armor of the dead. What am I?"
		}
	],
	"shop": {
		"boss_bait": {
			"description": "Lure forth a formidable Spectral Beast with this enchanted bait. Be prepared for a challenging encounter that may yield bountiful rewards in XP points and treasures.",
			"name": "Spectral Beast Bait",
			"price": 4000
		},
		"reversal_card": {
			"description": "Harness the power of karmic reversal with this mystical card. Use it to mirror your actions, experiencing the event of reversal and earning or **losing** spooky points in the process.",
			"name": "Karmic Reversal Card",
			"price": 10000
		},
		"treat_card": {
			"description": "Indulge in the sweetness of the Enchanted Treat Card. Use it to gift yourself or others a delightful treat, earning bonus XP points and fostering goodwill on your spiritual path.",
			"name": "Enchanted Treat Card",
			"price": 1500
		},
		"trick_card": {
			"description": "Invoke the Illusory Trickster Card to weave illusions and play tricks on yourself or others. This mysterious card may alter XP points and add a touch of whimsy to your cultivation journey.",
			"name": "Illusory Trickster Card",
			"price": 2500
		},
		"xp_boost1": {
			"description": "Unlock a **5%** XP boost for a magical **24-hour** journey.",
			"name": "Nocturnal Enigma Elixir",
			"price": 5555
		},
		"xp_boost2": {
			"description": "Embark on a **7-day** journey with a **5%** XP boost, cultivating ethereal energies for enlightenment.",
			"name": "Celestial Growth Elixir",
			"price": 38888
		},
		"xp_boost3": {
			"description": "Unleash a **10%** XP surge for **24 hours**, immersing yourself in spectral energies.",
			"name": "Haunting Essence Infusion",
			"price": 10555
		},
		"xp_boost4": {
			"description": "Extend your spectral growth over **7 days** with a **10%** XP boost.",
			"name": "Ephemeral Spectral Elixir",
			"price": 71888
		},
		"xp_boost5": {
			"description": "Ascend with a **15%** XP boost for **a day**, basking in the moonlit glow.",
			"name": "Lunar Ascendance Elixir",
			"price": 15555
		},
		"xp_boost6": {
			"description": "Savor a **15%** XP enhancement for **7 enchanted days**, embracing the twilight radiance.",
			"name": "Twilight Radiance Tonic",
			"price": 111888
		},
		"xp_points": {
			"description": "A vial containing rare Spectral Essence. Consume it to gain a substantial 1000 XP points, enhancing your otherworldly journey on the path of supernatural enlightenment.",
			"name": "Cultivation Essence",
			"price": 10000
		}
	},
	"treat": [
		"🍬 Behold, noble %s! You've reached for the ethereal sweetness of the Enchanting Treat, a confection beyond mortal delights. With each delightful bite, a shimmering mist surrounds you, transporting you to a realm of magic. Your journey earns you %d points in the ghostly ledger, a testament to your connection to the supernatural. Well done, adventurer!",
		"🍬 Greetings, seeker of delights, %s! As you savor the Enchanting Treat, the air is filled with a shimmering mist and magical sweetness. With each bite, you've earned %d points in the spectral realm, acknowledging your courage and connection to the supernatural. Bravo! May the magical sweetness linger in your memory.",
		"🍬 Oh, daring %s! The Enchanting Treat beckons, a magical confection that transports you to a realm where sweetness and mystery intertwine. With each delightful bite, points in the ghostly ledger accumulate—a total of %d to honor your bravery. Well done, noble soul!",
		"🍬 Hark, valiant %s! Beyond the virtual door, the Enchanting Treat reveals its enchanting nature. As you indulge in the magical sweetness, you've earned %d points in the ghostly ledger. The sweetness of the ethereal stands as a testament to your courage. Congratulations, adventurer!",
		"🍬 Greetings, seeker of delights, %s! The Enchanting Treat, a magical confection, reveals its sweetness beyond mortal understanding. With each delightful bite, you've earned %d points in the spectral realm, a reflection of your bravery and connection to the supernatural. Bravo, noble soul!",
		"🍬 Behold, brave %s! The Enchanting Treat, a confection beyond mortal sweetness, awaits. With each delightful bite, a shimmering mist surrounds you, and %d points in the ghostly ledger stand as a testament to your connection to the supernatural. Congratulations on your magical triumph!",
		"🍬 Noble %s, as you reach for the spectral door, the Enchanting Treat reveals its enchanting side. With each bite, you're transported to a realm where sweetness and magic intertwine. Points in the ghostly ledger, totaling %d, acknowledge your courage and connection to the supernatural. Well done, adventurer!",
		"🍬 Greetings, seeker of delights, %s! Alas, the Enchanting Treat has chosen a brighter path. Magical sweetness and delightful bites transport you to a realm where sweetness and mystery intertwine. In your encounter with the unseen confection, %d points are added to the ghostly ledger, marking the sweetness that illuminates your journey.",
		"🍬 Valiant %s, as you stand before the virtual door, the Enchanting Treat unveils its magical nature. With each delightful bite, you're transported to a realm where sweetness and magic intertwine. In your triumph, %d points in the ghostly ledger honor your courage. Congratulations on savoring the magical sweetness!",
		"🍬 Beware, daring %s! The Enchanting Treat, a confection beyond mortal sweetness, unveils its magical nature. With each delightful bite, a shimmering mist surrounds you, and %d points in the ghostly ledger acknowledge your connection to the supernatural. Well played, adventurer!"
	],
	"trickDouble": [
		"🔀 Greetings, %s! The Double Trick, a conjurer of spectral multiplication, now amplifies your spectral ledger. With a surge of otherworldly energy, your points undergo a doubling enchantment. Watch as your points multiply in the mystical dance of the Double Trick. Enjoy the spectral abundance!",
		"🔀 Behold, noble %s! The Double Trick, a weaver of spectral multiplication, extends its influence to your ghostly ledger. With a mystical incantation, your points undergo a transformation—doubling in magnitude. The symphony of the Double Trick adds a touch of abundance to your spectral journey. Enjoy the multiplication!",
		"🔀 Valiant %s, the Double Trick beckons, a sorcerer of point amplification. As you embrace the mystical energies, your points undergo a cosmic multiplication. Witness the magical abundance as your points double in the dance of the Double Trick. Enjoy the amplified journey!",
		"🔀 Greetings, seeker of mysteries, %s! The Double Trick, a maestro of spectral multiplication, now reveals its magic upon your ghostly ledger. With a cosmic surge, your points undergo a transformation—doubling in magnitude. Embrace the enchantment of abundance in your spectral journey!",
		"🔀 Noble %s, the Double Trick, a conjurer of spectral multiplication, now graces your spectral ledger. With a mystical incantation, your points undergo a doubling transformation. The dance of the Double Trick adds a touch of magical abundance to your spectral journey. Enjoy the symphony of multiplication!",
		"🔀 Greetings, %s! The Double Trick, a conductor of spectral multiplication, now plays its symphony upon your ghostly ledger. With a flicker of otherworldly energy, your points undergo a magical doubling. Embrace the mystical dance of abundance in your spectral journey!",
		"🔀 Oh, daring %s! The Double Trick, a sculptor of spectral energies, extends its influence to your spectral ledger. With a surge of ethereal magic, your points undergo a doubling enchantment. Witness the magical abundance as your points multiply in the dance of the Double Trick. Enjoy the amplified journey!",
		"🔀 Greetings, seeker of mysteries, %s! The Double Trick, a master of spectral multiplication, now reveals its magic upon your ghostly ledger. With a cosmic surge, your points undergo a transformation—doubling in magnitude. Embrace the enchantment of abundance in your spectral journey!",
		"🔀 Behold, brave %s! The Double Trick, a conjurer of spectral multiplication, now graces your spectral ledger. With a mystical incantation, your points undergo a doubling transformation. Enjoy the dance of magical abundance in your mystical spectral journey!",
		"🔀 Noble %s, the Double Trick beckons, a maestro of spectral multiplication. As you embrace the mystical energies, your points undergo a cosmic doubling. Witness the magical abundance as your points double in the dance of the Double Trick. Enjoy the multiplied journey!"
	],
	"trickHalf": [
		"⚖️ Greetings, brave %s! The Inversion Trick, a sorcerer of mystical transformation, now plays its symphony upon your ghostly ledger. With a flicker of otherworldly energy, your points undergo a mysterious halving. Enjoy the magical dance of inversion in your spectral journey!",
		"⚖️ Valiant %s, the Inversion Trick beckons, a maestro of spectral mystique. As you embrace the mystical energies, your points undergo a cosmic halving. Revel in the intriguing twist revealed in the dance of the Inversion Trick. Enjoy the reversal!",
		"⚖️ Greetings, seeker of mysteries, %s! The Inversion Trick, a master of spectral alchemy, now reveals its magic upon your ghostly ledger. With a cosmic twist, your points undergo a peculiar halving. Embrace the enchantment of inversion in your spectral journey!",
		"⚖️ Noble %s, the Inversion Trick, a weaver of spectral threads, now graces your spectral ledger. With a cosmic twist, your points experience a mystical revelation: they are halved. The dance of inversion adds a magical touch to your spectral journey. Enjoy the symphony of opposites!",
		"⚖️ Behold, noble %s! The Inversion Trick, a shaper of spectral destinies, extends its influence to your spectral ledger. With a mystical incantation, your points undergo a transformation—both are halved. A dance of spectral mysteries unfolds in the mirrored reflection of your spectral journey. Enjoy the intriguing inversion!"
	],
	"trickInv": [
		"🔄 Greetings, %s! The Inversion Trick, a master of reflection, now weaves its magic upon your spectral ledger. With a twist of spectral energy, your points undergo a reversal. Positive points become negative, and negative points become positive. A mirror image of your spectral journey awaits. Enjoy the inversion!",
		"🔄 Behold, noble %s! The Inversion Trick, a shaper of realities, extends its influence to your spectral ledger. With a mystical incantation, your points undergo a transformation—positive becomes negative, and negative becomes positive. A dance of opposites unfolds in the mirrored reflection of your spectral journey.",
		"🔄 Valiant %s, the Inversion Trick beckons, a sorcerer of point reversal. As you embrace the mystical energies, your points undergo a cosmic shift. Positive turns negative, and negative turns positive. The ebb and flow of your spectral ledger mirror the dance of the Inversion Trick. Enjoy the reversal!",
		"🔄 Greetings, seeker of mysteries, %s! The Inversion Trick, a maestro of spectral inversion, extends its influence to your ghostly ledger. With a twist of otherworldly energy, your points undergo a reversal—positive transforms into negative, and negative transforms into positive. Embrace the mystical symmetry of your spectral journey!",
		"🔄 Noble %s, the Inversion Trick, a weaver of spectral threads, now graces your spectral ledger. With a cosmic twist, your points experience a reversal—positive becomes negative, and negative becomes positive. The dance of inversion adds a mystical touch to your spectral journey. Enjoy the symphony of opposites!",
		"🔄 Greetings, %s! The Inversion Trick, a conductor of spectral reversal, now plays its symphony upon your ghostly ledger. With a flicker of otherworldly energy, your points undergo a transformation—positive becomes negative, and negative becomes positive. Embrace the magical dance of inversion in your spectral journey!",
		"🔄 Oh, daring %s! The Inversion Trick, a sculptor of spectral energies, extends its influence to your spectral ledger. With a twist of ethereal magic, your points undergo a reversal—positive transforms into negative, and negative transforms into positive. Witness the magical inversion of your spectral journey!",
		"🔄 Greetings, seeker of mysteries, %s! The Inversion Trick, a master of spectral alchemy, now reveals its magic upon your ghostly ledger. With a cosmic twist, your points undergo a transformation—positive becomes negative, and negative becomes positive. Embrace the enchantment of inversion in your spectral journey!",
		"🔄 Behold, brave %s! The Inversion Trick, a conjurer of spectral reflections, now graces your spectral ledger. With a mystical incantation, your points undergo a reversal—positive transforms into negative, and negative transforms into positive. Enjoy the dance of opposites in your mystical spectral journey!",
		"🔄 Noble %s, the Inversion Trick beckons, a maestro of spectral reversal. As you embrace the mystical energies, your points undergo a cosmic shift. Positive turns negative, and negative turns positive. The ebb and flow of your spectral ledger mirror the dance of the Inversion Trick. Enjoy the reversal!"
	],
	"trickNothing": [
		"❌ Greetings, %s! You attempt to invoke the power of the Reset Trick, seeking a purification of your spectral ledger. However, the mystical energies remain dormant, and the spectral dance of renewal eludes you for now. Embrace the journey with your current spectral points, and may the whims of the spectral realm favor you in future endeavors!",
		"❌ Alas, noble %s! As you reach out for the transformative magic of the Reset Trick, the ethereal forces seem to resist your plea for renewal. The dance of spectral cleansing remains still, and your points persist in their current state. Patience, adventurer, for the spectral realm holds many mysteries yet to unfold!",
		"❌ Valiant %s, in your pursuit of spectral renewal through the Reset Trick, the mystical energies remain serene and untouched. The cosmic reset eludes your grasp for now, and your spectral ledger retains its current essence. Fear not, for the dance of renewal may sway in your favor in the unfolding chapters of your spectral journey!",
		"❌ Greetings, seeker of mysteries, %s! As you beckon the magic of the Reset Trick, the spectral forces remain still. The cosmic reset, meant to cleanse your points, refrains from unveiling its magic. Embrace the mysteries of your current spectral journey, for the dance of renewal may yet weave its enchantment in unforeseen moments!",
		"❌ Noble %s, in your attempt to invoke the power of the Reset Trick, the mystical energies stand serene, resisting the call for spectral cleansing. The dance of renewal remains silent, and your spectral ledger maintains its current essence. Patiently tread the spectral path, for the whims of the spectral realm may unfold in unexpected ways!",
		"❌ Greetings, %s! As you reach for the transformative magic of the Reset Trick, the ethereal forces remain still, denying the expected cosmic reset. The dance of spectral renewal eludes your grasp for now, and your points persist in their current form. Embrace the mysteries of the spectral journey, for the dance of renewal may yet unfold in future chapters!",
		"❌ Oh, daring %s! In your pursuit of spectral cleansing through the Reset Trick, the mystical energies remain undisturbed. The dance of renewal, meant to transform your points, remains still, and your spectral ledger retains its current essence. Patiently traverse the spectral realm, for the dance of renewal may sway in your favor when least expected!",
		"❌ Greetings, seeker of mysteries, %s! As you invoke the power of the Reset Trick, the spectral forces remain undisturbed. The cosmic reset refrains from unfolding its magic, and your spectral ledger retains its current essence. Embrace the mysteries of your current spectral journey, for the dance of renewal may yet unveil its enchantment in the unfolding chapters!",
		"❌ Behold, brave %s! In your attempt to invoke the power of the Reset Trick, the mystical energies remain still, denying the expected cosmic reset. The dance of renewal remains silent, and your spectral ledger maintains its current essence. Patiently tread the spectral path, for the whims of the spectral realm may unfold in unexpected ways!",
		"❌ Noble %s, in your pursuit of spectral cleansing, the mystical energies resist the call for renewal. The cosmic reset remains silent, and your spectral ledger maintains its current essence. Patiently traverse the spectral realm, for the dance of renewal may yet unfold in future chapters!"
	],
	"trickReset": [
		"🌀 Greetings, %s! The Reset Trick, a master of spectral purification, now resets your spectral ledger to zero. With a purification ritual, your points are cleansed, offering a fresh start to your spectral journey. Embrace the purity of a blank slate and commence anew!",
		"🌀 Behold, noble %s! The Reset Trick, a weaver of spectral rejuvenation, extends its influence to your ghostly ledger. With a mystical incantation, your points are reset to zero. The symphony of the Reset Trick adds a touch of renewal to your spectral journey. Embrace the purified slate!",
		"🌀 Valiant %s, the Reset Trick beckons, a sorcerer of point renewal. As you embrace the mystical energies, your points undergo a cosmic reset. Witness the magical renewal as your spectral ledger is cleansed by the Reset Trick. Enjoy the fresh beginning!",
		"🌀 Greetings, seeker of mysteries, %s! The Reset Trick, a maestro of spectral cleansing, now reveals its magic upon your ghostly ledger. With a cosmic purification, your points are reset to zero. Embrace the enchantment of a blank slate in your spectral journey!",
		"🌀 Noble %s, the Reset Trick, a conjurer of spectral renewal, now graces your spectral ledger. With a mystical incantation, your points undergo a cleansing reset. The dance of the Reset Trick adds a touch of magical renewal to your spectral journey. Enjoy the symphony of purity!",
		"🌀 Greetings, %s! The Reset Trick, a conductor of spectral rejuvenation, now plays its symphony upon your ghostly ledger. With a flicker of otherworldly energy, your points are reset to zero. Embrace the mystical dance of renewal in your spectral journey!",
		"🌀 Oh, daring %s! The Reset Trick, a sculptor of spectral energies, extends its influence to your spectral ledger. With a surge of ethereal magic, your points undergo a cleansing reset. Witness the magical renewal as your spectral ledger begins anew. Enjoy the purified journey!",
		"🌀 Greetings, seeker of mysteries, %s! The Reset Trick, a master of spectral cleansing, now reveals its magic upon your ghostly ledger. With a cosmic purification, your points are reset to zero. Embrace the enchantment of a blank slate in your spectral journey!",
		"🌀 Behold, brave %s! The Reset Trick, a conjurer of spectral renewal, now graces your spectral ledger. With a mystical incantation, your points undergo a cleansing reset. Enjoy the dance of magical renewal in your mystical spectral journey!",
		"🌀 Noble %s, the Reset Trick beckons, a maestro of spectral cleansing. As you embrace the mystical energies, your points undergo a cosmic reset. Witness the magical renewal as your spectral ledger is cleansed by the Reset Trick. Enjoy the fresh beginning!"
	]
}
