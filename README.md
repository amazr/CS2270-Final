# CS2270 - Dictionary with Auto-Complete and Spell Check

# Description:
  Create a simple GUI word lookup program that includes auto-complete, spell-check, and stores a list of past looked up words. The word     look up, spell-check, and auto-complete will use a tree-like data structure known as a trie. Previously looked up words will be stored     using a linked list.
  
# Tools/Methods:
  Done using Qt: https://www.qt.io/ \n
  Using a trie for lookup, auto-complete, and spell check: https://en.wikipedia.org/wiki/Trie
  
# Proposed User Flow:
  Upon startup the program will display a simple interactable one-line text field. Once the user has narrowed the list of potential words   (to be determined how many that is, maybe will keep a list of common words and only suggest the ten most common possibilities) a box       will appear underneath displaying a vertical list of suggested words. One the user enters a character that makes the word invalid the     program will let the user know while suggesting corrections or similar words. 
  Once the user clicks on a word from the list below the text-field, the list will change into a simple page that displays the selected     words definition. To search for another word the user can simply type a new word in the text-field and a new list will appear.
  There will be a button on the right side of the text-field. When pressed this button will display a list of words the user previously     searched for. 

  



  
