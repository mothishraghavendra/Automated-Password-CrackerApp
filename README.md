# Trex

Trex is an Automated password cracking Application which was built on top of **John The Ripper tool**.

In general, John is a password cracking tool that uses various commands like:

- `pdf2john <filepath> hash.txt` : Extracts hashes from PDF files.
- `zip2john <filepath> hash.txt` : Extracts hashes from ZIP files.
- `7zip2john <filepath> hash.txt` : Extracts hashes from 7ZIP files.
- `john --wordlist=<file.txt> hash.txt` : Decrypts the extracted password using a wordlist.

Usually, these commands work in Kali Linux but not in Windows.

**TREX**, inspired by the name of the extinct species ***Tyrannosaurus Rex***, is designed so that users can use it in Windows too for cracking passwords. Users do not need to remember all these commands. Even though it is a CLI-based tool, it is automated, allowing users to select options displayed to them.
