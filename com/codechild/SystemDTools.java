package com.codechild;

public class SystemDTools {
  public long self = 0;
	// Functions that directly map into C
	public SystemDTools() {
	}
	public native int sd_notify( int unset_environment, String state );
}