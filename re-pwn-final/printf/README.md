# Challenge: printf

# Points: 50

#Description: 

Do you really know printf?

NOTE TO US:


2. While setting up, the user of **printf** executable should be **printf** it should be setuid to **printf_pwn**.

3. This is how convert printf into a setuid executable:

a. Create 2 users with names **printf** and **printf_pwn**. .
b. Change the owner of printf-executable to **printf_pwn** - chown printf_pwn printf
c. Change the group of printf-executable to **printf** - chgrp printf printf
d. Set the setuid bit: chmod u+s printf

So, a user with printf prvileges can also run executables with printf_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** .

4. There is a flag.txt with user **printf_pwn** and group **printf_pwn**. So, only withthe shell with privileges **printf_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **printf_pwn** user is able to read it and no one else.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-pri
vilege-users but this should happne in our case.

This is very very important!
