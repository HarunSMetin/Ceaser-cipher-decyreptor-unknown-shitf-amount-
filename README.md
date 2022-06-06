# Ceaser-cipher-decyreptor-unknown-shitf-amount-

Your program should take 3 arguments. <br />
'-r' : contains the name of the reference text document. <br />
'-c' : contains the name of the encrypted text document.  <br />
'-p' : specifies the name of the document in which the decrypted text will be written.
 <br /> <br />
Text documents contain only English characters and can be of variable length. The reference text document contains very long unencrypted text written in English. Using this reference text document, the code learns how to decode the encrypted text by analyzing which letter is used and how often. <br /> <br />

The ciphertext document contains a Caesar cipher-encrypted text and the amount of bias is unknown.<br /><br />

## EXAMPLES
~$./decrypt -r refa.txt -c ciphertext.txt -p plaintext.txt<br />
The refa.txt file could not be found.<br /><br />
~$./decrypt -r ref.txt -c cipahertext.txt -p plaintext.txt<br />
Could not find cipahertext.txt file.<br /><br />
~$./decrypt -r refa.txt -c cipahertext.txt -p plaintext.txt<br />
The refa.txt file could not be found.<br />
Could not find cipahertext.txt file.<br /><br />
~$./decrypt -r ref.txt -c ciphertext1.txt -p plaintext1.txt<br />
The amount of favoritism was determined as 5.<br />
The decoded text is written to plaintext1.txt.<br /><br />
~$./decrypt -r ref.txt -c ciphertext2.txt -p plaintext2.txt<br />
The amount of favoritism was determined as 3 (the most frequent letter) and 5 (the least frequent letter).<br />
The decoded text is written to plaintext2_0.txt and plaintext2_1.txt files.<br /><br />
