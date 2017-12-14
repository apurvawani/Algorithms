/*
Given month m , day d , and the sequence of integers written on each square of Lily's chocolate bar, how many 
different ways can Lily break off a piece of chocolate to give to Ron? Lily wants to give Ron a piece of chocolate 
only if it contains m consecutive squares whose integers sum to d.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class BirthdayChocolate {

    static int solve(int n, int[] s, int d, int m){
        int count = 0;
        for(int i = 0 ; i <= n-m ; i++){
            int j = 0 , sum = 0;
            while(j!=m){
                sum = sum + s[i+j];
                j++;
            }
            if(sum==d){
                count++;
            }
        }
        return count;
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] s = new int[n];
        for(int s_i=0; s_i < n; s_i++){
            s[s_i] = in.nextInt();
        }
        int d = in.nextInt();
        int m = in.nextInt();
        int result = solve(n, s, d, m);
        System.out.println(result);
    }
}
