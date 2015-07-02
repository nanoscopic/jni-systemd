import java.util.Iterator;
import com.codechild.SystemDTools;

class Test {
  public static void main(String[] args)
  {
    SystemDTools x = new SystemDTools();
    
    x.sd_notify( 0, "blah" );
  }
  static{
    System.loadLibrary("SystemDTools");
  }
}