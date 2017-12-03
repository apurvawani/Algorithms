/*

There are two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).
The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump. 
The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
Given the starting locations and movement rates for each kangaroo, can you determine if they'll ever land at the same 
location at the same time.

*/


import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.Math.*;

public class Kangaroo {

    static String kangaroo(int x1, int v1, int x2, int v2) {
        String result = new String("NO");
        int k1 = (x2 > x1)?1:0;
        int k2 = (v2 > v1)?1:0;
        if(k1==k2 || v1==v2) {
            return result;
        }
        else{
            /*while(s1!=s2){
                s1 = s1 + v1;
                s2 = s2 + v2;
                if(s1==s2){
                    result = "YES";
                }
            }*/
            int x = Math.abs(x2-x1);
            int v = Math.abs(v2-v1);
            if(x%v==0){
                result = "YES";
            }
            return result;
        }
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x1 = in.nextInt();
        int v1 = in.nextInt();
        int x2 = in.nextInt();
        int v2 = in.nextInt();
        String result = kangaroo(x1, v1, x2, v2);
        System.out.println(result);
    }
}
