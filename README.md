# TELEPHONE DIRECTORY FOR A CELLULAR SERVICE

Telephone Directory is a coding using C programming to store person name and telephone number in a file. The user can search a person contact that contain name and telephone number from a file. The user can also delete certain name that they want. Then, all the list will be sorted and display to the user.

# PREREQUISITES
This project requires the Dev-C++ or any other C and C++ language compiler.

# INSTALLATION

After open the compiler, click compile and run button. The program will display the menu of the project. User need to enter the number that user need. For adding new contact in the directory, enter 1. For deleting specific contact via name, enter 2. For search a contact, enter 3. For sorting all the existing contact, enter 4. For displaying all the contact, enter 5. Lastly, for exit the program, enter 6.



        =======================================================
         Welcome to telephone directory for a cellular service
        =======================================================
         Menu :
                1 Add new contact
                2 Delete specific contact via name
                3 Search contact
                4 Sort all existing contact
                5 Display all the contact
                6 Exit
        =======================================================

        -------------------------------------------------------
                ******************
                * Enter Choice:

____________________________________________________________________________________________________________________________________________________________________

If user enter 1, user need to insert name and telephone number below then click enter.The menu will be displayed again.


        -------------------------------------------------------
                ******************
                * Enter Choice:  1
                ******************
        -------------------------------------------------------
         Enter name: Kamarul
         Enter phone number: 0177658977


        ============================================================
         Menu :
                1 Add new contact
                2 Delete specific contact via name
                3 Search contact
                4 Sort all existing contact
                5 Display all the contact
                6 Exit

        ---------------------------------------------------------
                *****************
                *Enter Choice:

____________________________________________________________________________________________________________________________________________________________________

If the user enter the existed name or telephone number, the program will display that the name or telephone number is already in the contact. User need to enter different name or telephone number.

        -------------------------------------------------------
                ******************
                * Enter Choice:  1
                ******************
        -------------------------------------------------------
         Enter name: Kamarul
         Enter phone number: 0196587793

        < This name already exist in the contact >
           *  Please Enter another contact info  *

         Enter name:

____________________________________________________________________________________________________________________________________________________________________

If the user want to delete certain contact, enter 2 and enter the name to be deleted.The program will delete the name and display the latest list contact.

        -------------------------------------------------------
                ******************
                * Enter Choice:  2
                ******************
        -------------------------------------------------------

      Enter contact name or phone number you want to delete: Kamarul

         _________Successfully deleted_________
        |                                      |
        |          Name  : Kamarul             |
        |          Number: 1234567             |
        |                                      |
         --------------------------------------


        Latest list of the contact

        Name            Phone number
        ---------------------------------
        Imran           0186654897
	Aiman		0177166657

If the user delete non existed name, the program will display "This contact info does not exist in the contact".

        -------------------------------------------------------
                ******************
                * Enter Choice:  2
                ******************
        -------------------------------------------------------

        Enter contact name or phone number you want to delete: Luqman

        < This contact info does not exist in the contact >
             *   Please Enter another contact info   *

        Enter contact name or phone number you want to delete:
____________________________________________________________________________________________________________________________________________________________________

If the user want to search a contact that they want, enter 3 and enter the name to search. The program will display the name.

        -------------------------------------------------------
                ******************
                * Enter Choice:  3
                ******************
        -------------------------------------------------------
        Enter contact name you want to search: Imran

        Name: Imran
        Phone number: 0186654897


If the user search existed name, the program will display "*Name has not been found*" or "*Number has not been found*"
               
        -------------------------------------------------------
                ******************
                * Enter Choice:  3
                ******************
        -------------------------------------------------------
        Enter name to search: Luqman

       < This name is not found in the contact >

____________________________________________________________________________________________________________________________________________________________________

If the user want to sort the list by alphabet, enter 4. 

        -------------------------------------------------------
                ******************
                * Enter Choice:  4
                ******************
        -------------------------------------------------------


        Latest list of the contact

        Name            Phone number
        ---------------------------------------
        Aiman           0177166657
	Imran		0186654897
	---------------------------------------
____________________________________________________________________________________________________________________________________________________________________

If the user want to display all the list, enter 5.

        -------------------------------------------------------
                ******************
                * Enter Choice:  5
                ******************
        -------------------------------------------------------


        Latest list of the contact

        Name            Phone number
        ---------------------------------------
        Aiman           0177166657
	Imran		0186654897
	---------------------------------------

____________________________________________________________________________________________________________________________________________________________________

The program will exit if the user enter 6.

        -------------------------------------------------------
                ******************
                * Enter Choice:  6
                ******************
        -------------------------------------------------------

____________________________________________________________________________________________________________________________________________________________________



# AUTHORS

- Muhammad Luqman Bin Khirulnizam
- Maisarah Binti Alias
- Nur Syazwani Binti Nazaruddin
- Siti Hanisah Binti Lakman
- Wan Azfar Aiman Bin Wan Azmi


# ACKNOWLEDGMENTS

Thanks to all the team members who cooperated in completing this project until it was fully completed. Thanks also to Dr. Nordiana Binti Rahim who is a lecturer and advisor who gave advice on this project from time to time until it is fully completed.
