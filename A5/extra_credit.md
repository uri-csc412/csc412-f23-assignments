# Socially Responsible Computing (src): Character Sets (4 points)

The default string encoding in C, as you might recall from lectures uses the ASCII standard, which represents each character as one byte. ASCII is the American Standard Code for Information Interchange. However, ASCII is only meant for English and it does not support accents or characters from non-Latin alphabets.

To ensure that we are able to read in all player names that a user could input, and render them correctly, we will need to support a different character encoding. Programmers often turn to extended character sets (most commonly Unicode, and specifically its UTF-8 encodiing) to create more inclusive applications.

When programming for extended character sets, some of the standard library support functions for single character (ASCII) strings will not work as intended. C provides support for multibyte characters through their wchar_t struct, which represents a character in 4 bytes. However, since many extended character sets have variable length characters (for example, UTF-8 encodes characters in 1-4 bytes), using wchar_t leads to wasted space in memory. Moreover, programs often receive UTF-8 text as input that isn’t nicely laid out in 4-byte chunks, and must still be able to process it. (As an example, consider a website that processes input from a form: users may put strings like “γνωρίζω” or “❤️😺” into the form!)

UTF-8 characters follow a set byte format based on their length. 1 byte UTF-8 characters are meant to be compatible with ASCII, which means that they always begin with a 0 bit. For 2-4 byte UTF-8 characters, the number of leading 1s indicates the length of the character (in bytes). Each subsequent byte begins with the bits 10. You can find an overview of the format below:

|   Length (bytes)  |	Encoding (binary) |
| ------------- | -------- |
|   1	|   0xxxxxxx |
|   2	|   110xxxxx 10xxxxxx |
|   3	|   1110xxxx 10xxxxxx 10xxxxxx |
|   4	|   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx |

```
mbslen()
```

Now, to ensure that we are able to read in any name that a user could input, and render them correctly, we need to implement a function that will allow us to find the number of UTF-8 characters that a user inputs.

>**Task**: Implement mbslen() in mbstrings.c.

### mbslen: 
Counts the number of UTF-8 code points ("characters") in a UTF-8 encoded string.

#### Synopsis:
mbslen counts the number of code points in the UTF-8 multi-byte string stored in bytes until a null character is hit. Note that  the number of “characters” does not correspond to the number of bytes, but to the number of valid UTF-8 code points; see the UTF-8 encoding table for more details.
```
size_t mbslen(const char *bytes);
```

#### Examples:
```
char *emojis = "🥳😊😄";
size_t len = mbslen(emojis);  
// len = 3
```

>**Task**: Once you have successfully implemented mbslen(), call it in snake.c on the name the user inputs and store the result in the appropriate place.

We’re almost done! Let’s tie it all together and present the game over screen.

>**Task**: Edit end_game(…) and uncomment the lines around and including render_game_over(…) (which implicitly requires the name and its length) so that your snake game renders the final screen when the game is over.

> ☑️ Testing Point G: You should pass all the tests at this point! You should be able to prompt a user for their name, and then store their name and name’s length (according to unicode characters), and see the final game over screen rendered when a game ends.

#### Include charsets.md in your Gradescope submission

> Please describe your implementation and how to test it in a new file charsets.md. The amount of TA help you can get here may be limited. 


# Unicode and Reflection Questions (4 points)

>**Task**: Write your answers to the following three questions in the SRC section of your README. Please note that you will need to consult a classmate for Question 3! You will be given the opportunity to find a partner in your section. If you have special circumstances or encounter any difficulty, please contact us and we will match you with a classmate.

The primary goal of the Unicode character encodings is to accurately represent “all characters in widespread use today.” With that, the Unicode Consortium (https://www.unicode.org/consortium/consort.html), the organization responsible for maintaining and updating the Unicode standard, must appropriately decide which characters to include.

Who founded the Consortium? Who is represented among the current members, and how might that affect decisions being made for Unicode?
Accounting for every possible language is difficult; the Unicode standard supports many, but not all.

Find a language that is not yet in Unicode, has only recently been supported (e.g., in the last 10 years), or is/was missing important characters. What is/was missing, and how does this affect the users of the language?

Beyond missing languages and characters in languages, Unicode has also faced controversies with representing (and unifying) similar languages. One of the biggest controversies is Han Unification, an attempt to unify the Chinese, Japanese, and Korean (CJK) languages into one common encoding. This Unicode Technical Note explains why CJK languages are unified, while Latin, Greek, and Cyrillic scripts aren’t. Meanwhile, Suzanne Topping of IBM explains some of the downfalls of this decision:

The problem stems from the fact that Unicode encodes characters rather than “glyphs,” which are the visual representations of the characters. … While the Han root character may be the same for CJK languages, the glyphs in common use for the same characters may not be.

For example, the traditional Chinese glyph for “grass” uses four strokes for the “grass” radical, whereas the simplified Chinese, Japanese, and Korean glyphs use three. But there is only one Unicode point for the grass character (U+8349) regardless of writing system. Another example is the ideograph for “one,” which is different in Chinese, Japanese, and Korean. Many people think that the three versions should be encoded differently.

For this question, you will need to work with a classmate! Make sure to coordinate so that you outline opposing positions for Part A (e.g. if you outline the ‘for’ position, your partner defends the ‘against’ position). Then, come together and discuss Part B!

#### Include unicode.md in your Gradescope submission

> The amount of TA help you can get here may be limited. 
* Partner’s URI email address login
* Your individual answer to Part A
* A bullet-point summary of your discussion for Part B. You should be summarizing both the conclusion you came to, and the process by which you got there (e.g. disagreements you had, ideas you had in common, convincing evidence you encountered, etc.)
* a. Outline either the position for Han Unification, or the position against Han Unification.
* b. Describe the tradeoff that Unicode has made with this decision. Which “goods” (e.g. accuracy, efficiency, fairness, sustainability) did they choose to prioritize?

You did it!! 😃 

Go get some high scores (and post them on Ed) 🎮

# Improve Snake (up to 8 points)

If you’re feeling adventurous, try to extend your game with some additional fun features! 

> Make sure to gate your extra credit with a command line flag, special optional characters in board strings, or a #define so that existing tests don’t break. We will not be modifying the existing tests or autograder to work with any changes you make

#### Include snake.md in your Gradescope submission

> Please describe your implementation and how to test in a new file snake.md. The amount of TA help you can get here may be limited. 

#### Gameplay

Grow more than one length on each food
You may find that some online snake implementations have the snake grow more than one unit on each food. #define a constant that corresponds to the snake’s growth length, and have the snake grow accordingly (2 points).


#### Make a bot

Create a simple bot that plays your game by moving the snake in random directions! (3 points).

Go beyond the simple bot — make it do :sparkles: better :sparkles: (3 points).

#### Powerups!

MULTISNAKE (2 points for design, 4 for implementation).
Multi-speed snake? Support areas of the board (or items the snake can collect) that make it slower or faster. 
[Hint: recall that we use bit flags to represent cell state, so a cell could be in "slippery" state and change the snake speed when the snake is on it!].

Set your creativity free with the following freestyle ideas! Figure out what thesy could mean and add support to the game. There is no right or wrong design here, just FUN 🥳!
 
* A snake that shrinks??? (2 points).
* Temporarily Incorporeal Snake? (2 points).
* Extra Life Snake? (2 points).
* Enemy snakes (4 points).
* Rainbow invincible snake (2 points).

#### Wraparound
We currently do not define behavior when the snake hits the edge of the board (N.B.: the edge, not an outside wall). Make it so that the snake wraps around to the other edge when it runs off the board. (4 points)

#### Visuals

These ideas will likely involve working with the renderer (render.c), which uses the ncurses and ncursesw libraries (for wide character support).

#### Better Snake visuals
Rather than rendering “S” characters, make a solid green snake [Hint: use Unicode characters like we do for the walls] (2 points).

Make the food look like food [Hint: Unicode food emojis] (2 points).

#### Bell character on food 🔔
Read about the “bell” character (ASCII 0x7, Unicode U+0007) and then add it to the game at relevant points. (2 points)

#### Better UI
Add a startup menu screen (2 points).

Add a pause menu screen (1 point).

Add a high score board! For this, you’ll need to be able to run the game multiple times on one run of snake.c, and find a data structure to track high scores. (3 points.)

#### Misc

##### Interesting Level Design

Make a cool level and share it on EdStem and then...

Make the coolest level as voted by your peers (1 point, gold star and a round of applause).

Recreate a Tyler Hall's floorplan as a level (2 points).