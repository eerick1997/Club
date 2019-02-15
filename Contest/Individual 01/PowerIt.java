import java.math.*;
import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        BigInteger X, Y, N, ans;
        int T = scanner.nextInt();  
        for(int i = 0; i < T; i++){
            X = scanner.nextBigInteger();
            Y = scanner.nextBigInteger();
            N = scanner.nextBigInteger();
            ans = X.modPow(Y, N);
            System.out.println(ans);
        }
    }
}