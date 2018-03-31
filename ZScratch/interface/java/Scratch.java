package ZScratch.interface.java

public interface ScratchExtension {
	String extid;
	String title;
	public abstract ScratchExtension();
	public abstract void pre_init();
	public abstract void init();
	public abstract void post_init();
}

