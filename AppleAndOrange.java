import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class AppleAndOrange {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        int t = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int m = in.nextInt();
        int n = in.nextInt();
        int[] apple = new int[m];
        for(int apple_i=0; apple_i < m; apple_i++){
            apple[apple_i] = in.nextInt();
        }
        int[] orange = new int[n];
        for(int orange_i=0; orange_i < n; orange_i++){
            orange[orange_i] = in.nextInt();
        }
        int noOfApples = 0;
        for(int apple_i=0; apple_i < m; apple_i++) {
                int r = a + apple[apple_i];
            if(r>=s && r<=t){
                noOfApples++;
            }
        }
        System.out.println(noOfApples);
        int noOfOranges = 0;
        for(int orange_i=0; orange_i < n; orange_i++) {
            int r = b + orange[orange_i];
            if(r>=s && r<=t) {
                noOfOranges++;
            }
            
        }
        System.out.println(noOfOranges);
    }
}
