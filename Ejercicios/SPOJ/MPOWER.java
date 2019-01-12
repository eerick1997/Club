import java.math.*;
import java.util.*;

public class MPOWER{

    public static BigInteger power_big_integer(BigInteger a, BigInteger b, BigInteger m){
        BigInteger n = BigInteger.ONE;
        BigInteger b_two = BigInteger.valueOf(2);
        while(b.compareTo(BigInteger.ZERO) == 1){
            if(b.mod(b_two).equals(BigInteger.ONE))
                n = n.multiply(a).mod(m);   
            b = b.divide(b_two);
            a = a.multiply(a).mod(m);
        }
        return n;
    }

    public static void main(String[] args){
        BigInteger a, e, m;
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int i = 0; i < t; i++){
            a = scanner.nextBigInteger();
            e = scanner.nextBigInteger();
            m = scanner.nextBigInteger();
            System.out.println(power_big_integer(a, e, m));
        }
    }
}