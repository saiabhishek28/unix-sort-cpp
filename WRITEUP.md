FILES PRESENT IN LAB - 0 --> main.cpp, Makefile, and sort.h

<main.cpp> - 

Contains the main part of the program. The most crucial part of the main.cpp is to process and parse through the command line arguements. 
Certains checks that are included in the main are:
    1. command line check to see if "--name" is given by the user, and if its then it prints the name (Sai Abhishek Aravind)
    2. next check is to see if the syntax given is correct. it checks for "-o" for the output file.
    3. it stores the name of the file to be read and the name of the output file in separate variable.
    4. MOST IMPORTANT CHECK IS TO SEE WHAT ALGORITHM THE USER HAS GIVEN. For this Alg_Logic variable is used.
    5. first I clear the first 6 characters from the 3rd arguement which is the --alg=<merge,quick>.
    6. "--ALG=" are the first 6 characters and after deleting them from the string we are left with either MERGE or QUICK.
    7. Simple IF condition is used to check which algorithm the user wants to use.
    8. if alg_logic == merge, then mergesort function is called. 
    9. if alg_logic == quick, then the quick sort function is called.
    10. both functions accept a vector as an arguement and make the changes to the same vector itself. they have VOID return type.
    11. after the function is called, the output file is opened and the contents of the sorted vector are written.
    12. END.
    
    
<sort.h> - 

Contains the main logic for merge and quick sort.
    MERGE SORT - since merge sort is written using divide and conquer methodology and has recursive calls.
        it has 2 main functions. one to merge, and one to sort.
        Basically the idea behind merge sort is to keep dividing the initial vector into smaller partitions untill there is only one element left and then we  sort them. After that we need to merge all the elements giving the sorted array. Time Complexity - O(n x Log n).
        Merge sort has 2 different functions called merge and merge_sort.
    QUICK SORT - Like merge sort, quick sort is also using a divide and conquer idea and has recursive calls.
        The idea behind quick sort is to choose a pivot element in the array. In my program, pivot element is the last element of the array.
        First we have to make the elements that are smaller than pivot element to be on the left side of the pivot element, and larger numbers to be in the
        right side. when we do that the pivot element is automatically sorted.
        Then once thats done, we will partition the main vector into 2 sub-vectors, one from start to pivot index ,and other from pivot index to end.
        Now for these 2 vectors again the same process of allocating pivot element is done and the whole process is repeated until all the sub vectors contain
        only one element. this means that the integers are sorted. All we need to do is to combine the elements to form the final sorted array.
    
    Once the sort (merge or quick) is called by main.cpp, the changes are made to the vector given as a parameter to the sort function.
    
    
 <Makefile> -
    
 Output part contains the main.o which runs the last and it sets our final executable file name to "mysort".
 Then main.o is defined as g++ -c main.cpp. This command runs first. it executes main.cpp and then builds the output file into mysort. 
    Finally we use clean to clean the output of other targets. 
    
<EXTANT BUGS & BUGS resolved>
    
        my code initially was buggy, though it didnt throw errors. Several logical errors were dealt with, especially when dealing with vectors and
    passing vectors as parameters to the function calls. Most errors were fixed when I changed to call by reference instead of value.{ vector <int> & v; }
    
    Sometimes while running it gave a memory allocation error, but it was fixed when I compiled main.cpp again. 
        
        
---------------------------------------------------------------------------------------------------------------------------------------------------------------