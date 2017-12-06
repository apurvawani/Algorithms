/*
Given a string 's' consisting of 'n' lowercase English alphabetic letters , delete any pair of adjacent letters with 
same value as many times as possible and print the final non-reducible string.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
 
public class Solution {

    static String super_reduced_string(String s){
        boolean check = true;
        String result = "";
        while(check){     
            char[] arr = s.toCharArray();
            String s_i = "";
            for(int i = 1 ; i < arr.length ; i++) {
                if(arr[i-1]==arr[i]) {
                    i++;
                }
                else {
                    s_i +=arr[i-1];
                }
                if(i==arr.length - 1) {
                    s_i += arr[i];
                }
            }
            if(s_i.length()==0) {
                s_i = "Empty String";
                return s_i;
            }
            else {
                char[] a = s_i.toCharArray();
                for(int j = 1 ; j < a.length ; j++){
                    if(a[j-1]==a[j]){
                        check = true;
                        s = s_i;
                        break;
                    }
                    else {
                        check = false;
                        result = s_i;
                    }
                }
            }
        }
        return result;
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String result = super_reduced_string(s);
        System.out.println(result);
    }
}
