/*
Consider two sets of positive integers, A={a0,a1,a2....an-1} and B={b0,b1....bn-1} . We say that a positive integer,x
is between sets A and B if the following conditions are satisfied:
1. All elements in A are factors of x.
2. x is a factor of all elements in B.
find and print the number of integers (i.e., possible x's) that are between the two sets.
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class BetweenTwoSets {

    static int getTotalX(int[] a, int[] b) {
        int max = a[0];
        int min = b[0];
        int n = a.length;
        int m = b.length;
        for(int a_i = 0; a_i < n; a_i++){
            if(a[a_i] > max){
                max = a[a_i];
            }
        }
        for(int b_i = 0; b_i < m; b_i++){
            if(b[b_i] < min){
                min = b[b_i];
            }
        }
        int count = 0;
        boolean check1=false , check2=false;
        if(min%max!=0){
            return count;
        }
        else {
            do{

            for(int a_i = 0; a_i < n; a_i++){
                if(max%a[a_i]!=0){
                    check1 = false;
                    break;
                }
                else{
                    check1 = true;
                }
            }
            /*if(check1==true){
                count++;
            }
            else{
                max = max * 2;
            }*/
            for(int b_i = 0; b_i < m; b_i++){
                if(b[b_i]%max!=0){
                    check2 = false;
                    break;
                }
                else{
                    check2 = true;
                }
            }
            /*if(check2==true){
                count++;
            }
            else{
                min = min - max;
            }*/
            
            if(check1==true && check2==true){
                count++;
            }
            /*int i = 3;
            max = max * 2;
                if(min%max==0){
                    count++;
                }*/
                max++;
            }while(max!=min+1);
            return count;
        }
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for(int a_i = 0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        int[] b = new int[m];
        for(int b_i = 0; b_i < m; b_i++){
            b[b_i] = in.nextInt();
        }
        int total = getTotalX(a, b);
        System.out.println(total);
        in.close();
    }
}
