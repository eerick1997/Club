import java.util.*;
import java.math.*;

//Write Main instead of pseudoprime_numbers
public class pseudoprime_numbers{

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        
        while(true){
            BigInteger p = scanner.nextBigInteger();
            BigInteger a = scanner.nextBigInteger();
            if(p.equals(BigInteger.ZERO) && p.equals(BigInteger.ZERO))
                break;
            
            if(p.isProbablePrime(15)){
                System.out.println("no");
            } else if(a.modPow(p,p).equals(a)){
                System.out.println("yes");
            } else {
                System.out.println("no");
            }

            
        }
    }
}