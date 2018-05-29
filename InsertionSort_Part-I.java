/*
Given a sorted list with an unsorted number 'e' in the rightmost cell, can you write some simple code to insert into 
the array so that it remains sorted? 
Assume you are given the array arr = [1,2,4,5,3] indexed 0...4. Store the value of arr[4]. Now test lower index 
values successively from 3 to 0 until you reach a value that is lower than arr[4], arr[1] in this case. Each time 
your test fails, copy the value at the lower index to the current index and print your array. When the next lower 
indexed value is smaller than arr[4], insert the stored value at the current index and print the entire array.
*/


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the insertionSort1 function below.
    static void insertionSort1(int n, int[] arr) {
        int key = arr[n-1] , i;
        for(i = n-2 ; i >= 0 ; i--) {
            if(arr[i] > key) {
                arr[i+1] = arr[i];
            }
            else {
                arr[i+1] = key;
                break;
            }
            for(int j = 0 ; j < n ; j++) {
                System.out.print(arr[j]);
                System.out.print(" ");
            }
            System.out.println();    
        }
        if(i==-1) {
            arr[0] = key;
        }
        for(int j = 0 ; j < n ; j++) {
            System.out.print(arr[j]);
            System.out.print(" ");
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        insertionSort1(n, arr);

        scanner.close();
    }
}
