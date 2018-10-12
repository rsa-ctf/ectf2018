# Challenge: mcode

# Points: 75

# Description:

Did you know even you can inject and run pure machine code??

Look at [this](./mcode) executable.
[This](./mcode.c) is the sourcefile.

# Hint:

1. Suppose you want machine code of exit(1), then write code for it in C, get the executable and disassemble it. You can look at machine code of respective assembly instructions. 

2. It is not that straight forward, you will have to hack it :P



NOTE to us:

2. While setting up, the user of **mcode** executable should be **mcode** it shouldbe setuid to **mcode_pwn**.

3. This is how convert mcode into a setuid executable:

a. Create 2 users with names **mcode** and **mcode_pwn**. .
b. Change the owner of mcode-executable to **mcode_pwn** - chown mcode_pwn mcode
c. Change the group of mcode-executable to **mcode** - chgrp mcode mcode
d. Set the setuid bit: chmod u+s mcode

So, a user with mcode prvileges can also run executables with mcode_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** .

4. There is a flag.txt with user **mcode_pwn** and group **mcode_pwn**. So, onlywiththe shell with privileges **mcode_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **mcode_pwn** user is able to read it and no one else.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-privilege-users but this should happne in our case.

