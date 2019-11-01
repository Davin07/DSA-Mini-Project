<h1> Implementation of Cryptography </h1>


The entire project  will consist of two main programs - "Encryption" and "Decryption".

----------------

The first program - "Encryption" will be for, as the name suggests, encryption of user-inputed text.
The user will be asked to input the text he/she wishes to encrypt. A random encryption algorithm among the following:
1. Keyword Cipher
2. Caesar Cipher
3. XOR Cipher
4. ROT13 Cipher
5. Vernam Cipher
6. Vigenere Cipher
7. Playfair Cipher
8. Polybius Square Cipher
9. Atbash Cipher
10. Latin Alphabet Cipher 

is chosen and used to encrypt the text inputed by the user.

If the encryption method requires a key, the user is asked to a input a key. The key plays an integral role in the encryption of the text. Without knowledge of the key, it should be extremely difficult, if not impossible, to decrypt the resulting ciphertext into readable plaintext.

On entering the text to be encrypted, a random encryption algorithm is selected and the key may or may not be asked. On accepting all the required inputs, the program encrypts the input-text accordingly and provides it as output. 

------

The second program - "Decryption" decrypts already encrypted text inputed by the user. 

This program has two different operation flows: 

1. This operation flow caters to the scenario where the user already has a certain encrypted text in his possesion and knows the type of encryption algorithm that was used while ciphering and also the key if necessary. It should be noted that, this operation flow can be used only if the algorithm used to ciper the text that the user possess, is among the list of algorithms used in the first program. Failing which, the user will not be able to decrypt his message using this particular program.  

2. This operation flow is linked with the previous program, where the user has received an encrypted message corresponding to the text he/she gave as input and a key if any. This program decrypts the encrypted message from the previous program and provides the message as plain text to the user. It does so, by storing the index value of the randomized algorithm chosen and also the encrypted message in a file. The values stored in the file are then extracted from it and used accordingly while decrypting.
                                                                          

