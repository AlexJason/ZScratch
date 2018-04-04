package ZScratch.interface.java

public interface ScratchExtension {
	String extid;
	String title;
	public abstract ScratchExtension();
	public abstract void preInitialisation();
	public abstract void Initialisation();
	public abstract void postInitialisation();
}

