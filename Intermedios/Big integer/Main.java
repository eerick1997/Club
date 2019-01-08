import java.util.*;
import java.math.*;

public class Main(){
    public static void main(){
        String n;
        String ans = "";
        for(int i = 0; i < 300; i++)
            ans += "0";

        Scanner s = new Scanner(System.in);
        while(true){
            n = s.nextLine();
            if(n.equals("0"))
                break;
            
            for(int i = 0; i < n.size(); i++){
                String str = "";
                for(int j = i; j < n.size(); j++){
                    str += n.charAt(j);
                }
                str.trim();
                BigInteger numb = new BigInteger(str);
                if(numb.probablePrime(10) && str.size() < ans.size()){
                    ans = str;
                }
            }
            System.out.println(ans);
        }
    }
}