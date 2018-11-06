#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
/*
    //understand pointer
    int a = 10;
    int *ptr_a= &a; // save a's pointer value in ptr_a

    *ptr_a=10; // pointer(ptr_a)'s original value(a) = 20
    printf("ptr_a's value :%d\n", ptr_a);
    printf("ptr_a's value+1 :%d\n", ptr_a+1);
    //if add 1 to pointer, it increase number as the size of arry[0]
*/
/*
    // understand pointer in array(increase as the size
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    //printf("arr's value : %d\n", arr); //arr = &arr[0]
    for (int i =0; i<10;i++){
        printf("&arr[%d] = %d\n",i,&arr[i]);
        printf("arr+%d = %d\n",i,arr+i);
    }
*/
/*
    //arr[]'s arr means arr's address value(ptr[0])
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    //printf("arr's value : %d\n", arr); //arr = &arr[0]
    for (int i =0; i<10;i++){
        printf("%d",i,&arr[i]);

    }
    printf("\n");

    for(int i =0;i<10;i++){
        printf("%d", *(arr+i));
    }
    printf("\n");

    for(int *ptr= arr; ptr<arr+10;ptr++){
        printf("%d",*ptr);
    }
    printf("\n");
    */
    /*
    //same value of many expression
    int arr[3]= {1,2,3};
    int *ptr= arr;

    for (int i =0;i<3;i++){
        printf("%d", *(ptr+i));
    }

    for(int i =0;i<3;i++){
        printf("%d",ptr[i]);
    }
    printf("\n");


    //arr[i] == *(arr+i) ==*(ptr+1) == ptr[i] ==i[ptr]
    // a[b] -> *(a+b)
    */
/*
    1. ptr ==&ptr[0]
    2. *ptr == ptr[0]
    3. ptr+1 == value that ptr + sizeof(*ptr)

*/
/*
    int arr[3] = {1,2,3};

    printf("arr= %d\n", arr);
    printf("arr +1 = %d\n", arr+1); // added 4

    printf("&arr = %d\n", %arr);
    printf("&arr+1 = %d\n", &arr +1 ); // added 12(int*3)

*/
/*
    //array pointer
    int arr[3]= {1,2,3};
    int(*ptr_arr)[3] // declare int type pointer which size is 3
    ptr_arr = &arr;

    for (int i ; i<3;i++){
        printf("d\n", (*ptr_arr)[i]);
    }
*/
// #27 2dimensional array and array pointer
/*

    int arr[2][3]= { {1,2,3}, {4,5,6}};

    printf("%d", sizeof(arr)); //24
    printf("%d", sizeof(arr[0])); //12
    printf("%d", sizeof(arr[0][0])); //4

    //every things are same
    printf("%d", &arr);
    printf("%d", &arr[0]);
    printf("%d", arr[0][0]);
*/

/*
    // if want to make pointer to save address of 2 dimension array
    // -> declare 1 dimensional pointer int (*ptr)[i] = %arr[0]

     int arr[2][3]= { {1,2,3}, {4,5,6}};

     int(*ptr)[3]= &arr[0];

     //1. ptr[i] == arr[i]
     //2. ptr[i][j] == arr[i][j]
     // ptr ==arr


     for (int i=0 ; i<2;i++){
        for (int j=0 ; i<3; i++){
            printf("%d", ptr[i][j]);
        }
        printf("\n")
     }
*/
/*
    int arr[2][3]= { {1,2,3}, {4,5,6}};

    for(int(*row)[3] = arr; row <arr+2; row++){
        for(int *col = *row ; col<*row+3 ; col++){
            printf("%d", *col);
        }
        printf("\n");
    }
*/

//Pointer array :Pointer's array
//array pointer : pointer that point array


/*
    int arr[4] ={1, 2, 3, 4};
    int *ptr[4];

    for (int i = 0 ; i<4;i++)
    {
        ptr[i] = &arr[i];
    }

    for (int i = 0 ; i<4;i++)
    {
        printf("%d", *ptr[i]);
    }
    printf("\n");
*/

    //char str[] = "Hello";
    //printf("%s\n", &str[0]);
    // if input the pointer of str[0] then %s print array till null

    char strings[3][10] = {"Hello","World","Doodle"};
    char *p_str[3];

    for (int i =0; i<3; i++)
    {
        p_str[i]= strings[i];
    }




    for (int i =0;i<3;i++)
    {
        printf("%s\n", &strings[i][0]);
        printf("%s\n", &strings[i]);
    }
    printf("\n\n");

     for (int i =0;i<3;i++)
    {
        printf("%s\n", p_str[i]);
    }




}
