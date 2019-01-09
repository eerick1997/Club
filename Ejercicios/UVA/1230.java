import java.math.*;
import java.util.*;

//Write Main instead of modex
public class modex{

    public static void main(String args[]){
        int cases = 0;
        Scanner scanner = new Scanner(System.in);

        while(true){
            
            cases = scanner.nextInt();
            if(cases == 0) 
                break;
            for(int i = 0; i < cases; i++){
                BigInteger x = scanner.nextBigInteger();
                BigInteger y = scanner.nextBigInteger();
                BigInteger n = scanner.nextBigInteger();
                System.out.println(x.modPow(y, n));
            }
        }
    }

}