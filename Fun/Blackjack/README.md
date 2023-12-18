# Yag-CC | Blackjack 

## Setting up Blackjack Custom command
**Step 1**: Add [Main CC](Fun/Blackjack/main-bj.go), Trigger type: `regex`, Trigger: 
```
\A(?:\-|<@!?204255221017214977>)\s*((?:b(?:lack)?j(?:ack)?)|(?:bal(?:ance)?)|(?:give(?:balance)?)|(?:add(?:balance)?))(?: +|\z)
```

**Step 2**: Add [Reaction Handler CC](Fun/Blackjack/reaction-bj.go), Trigger type: `reactions`, select `added reactions only`

>❗ Disable Error output on reaction CC. <br>
> ⚠️ Card Emojis are in my private server, if u are using selfhost, u have to change the emoji name:ID or ask me to invite your selfhost to emoji server. 

## Commands 
- `-bj` or `-blackjack` : to to play the game without any bets.
- `-bj <amount>`: to play blackjack with bet.  <details>
  <summary>-blackjack</summary>
  <img src="https://github.com/Shadow21AR/Yag-CC/blob/38ffe96b33a21783209a042c9e6cf96e480f0f7f/img/Blackjack/lose.jpg" name="Loss">
  <img src="https://github.com/Shadow21AR/Yag-CC/blob/38ffe96b33a21783209a042c9e6cf96e480f0f7f/img/Blackjack/win.jpg" name="Win">
  <img src="https://github.com/Shadow21AR/Yag-CC/blob/38ffe96b33a21783209a042c9e6cf96e480f0f7f/img/Blackjack/tie.jpg" name="Tie"> </details>

- `-bal` : to check balance 
- `-bal @user` : to check user balance <details> <summary> -bal </summary> <img src="https://github.com/Shadow21AR/Yag-CC/blob/38ffe96b33a21783209a042c9e6cf96e480f0f7f/img/Blackjack/bal.jpg"> </details>
- `-add @user <amount>` : to ADD the CREDITS [Admin ONLY]
- `-give @user <amount>` : to transfer the CREDITS. 


Copyright (c): Shadow21A

> If u got any ideas / bugs to share , contact me on discord : `@shadow21a` or u can find me on yagpdb support server.
