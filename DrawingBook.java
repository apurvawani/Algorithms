/*
Brie’s Drawing teacher asks her class to open their n-page book to page number p. Given n and p, find and print the 
minimum number of pages Brie must turn in order to arrive at page p.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class DrawingBook {

    static int solve(int n, int p){
        if(n%2==0){
            n++;
        }
        if(p==1 || p==n){
            return 0;
        }
        else{
            int r = n - p;
            if(r > p){
                return p/2;
            }
            else{
                return r/2;
            }
        }
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int p = in.nextInt();
        int result = solve(n, p);
        System.out.println(result);
    }
}
 
