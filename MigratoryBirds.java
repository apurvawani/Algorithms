/*
Given an array of n integers where each integer describes the type of a bird in the flock, find and print the type 
number of the most common bird. If two or more types of birds are equally common, choose the type with the smallest 
ID number.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.util.Arrays;

public class MigratoryBirds {

    static int migratoryBirds(int n, int[] ar) {
        Arrays.sort(ar);
        int count_i = 0;
        int[][] a = new int[n][2];
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(ar[i]==ar[j]){
                    count_i++;
                }
                else {
                    break;
                }
            }
            a[i][0] = ar[i];
            a[i][1] = count_i;
            count_i = 0;
        }
        int max = a[0][1] , index = 0;
        for(int i = 1 ; i < n ; i++){
            if(a[i-1][1] < a[i][1]){
                max = a[i][1];
                index = i;
            }
        }
        return a[index][0];
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] ar = new int[n];
        for(int ar_i = 0; ar_i < n; ar_i++){
            ar[ar_i] = in.nextInt();
        }
        int result = migratoryBirds(n, ar);
        System.out.println(result);
    }
}
