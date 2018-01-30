/*
Given the price lists for the store's keyboards and USB drives, find and print the amount of money Monica will spend.
(the total cost of her purchase must be maximal).
If she doesn't have enough money to buy one keyboard and one USB drive, print -1 instead.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int getMoneySpent(int[] keyboards, int[] drives, int s){
        int n = keyboards.length;
        int m = drives.length;
        Arrays.sort(keyboards);
        Arrays.sort(drives);
        int max = 0;
        for(int i = n-1 , j = 0 ; i >= 0 ; i--){             
            for(; j < m ; j++){                  //Important!! 'j' is inialized to 0 only once. It is not O(n x m).
                int sum = keyboards[i] + drives[j];
                if(sum > max && sum <= s){
                    max = sum;
                }
                if(sum >= s){
                    break;
                }
            }
            if(j==m){
                j--;
            }
        }
        if(max==0){
            return -1;
        }
        else{
            return max;
        }
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        int n = in.nextInt();
        int m = in.nextInt();
        int[] keyboards = new int[n];
        for(int keyboards_i=0; keyboards_i < n; keyboards_i++){
            keyboards[keyboards_i] = in.nextInt();
        }
        int[] drives = new int[m];
        for(int drives_i=0; drives_i < m; drives_i++){
            drives[drives_i] = in.nextInt();
        }
        int moneySpent = getMoneySpent(keyboards, drives, s);
        System.out.println(moneySpent);
    }
}
