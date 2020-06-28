package smartInterface.models;

public class Switch {
	
	private String name;
	private int status;
	private int dimmerStatus;
	private int withName;
	
	public Switch() {
		name = "";
		status = 0;
		dimmerStatus = 0;
		withName = 0;
		
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int getStatus() {
		return status;
	}
	
	public void setStatus(int status) {
		this.status = status;
	}
	
	public int getDimmerStatus() {
		return dimmerStatus;
	}
	
	public void setDimmerStatus(int dimmerStatus) {
		this.dimmerStatus = dimmerStatus;
	}
	
	public int withName() {
		return withName;
	}
	
	public void saveName() {
		withName = 1;
	}
	
	public void changeName() {
		withName = 0;
	}
}
