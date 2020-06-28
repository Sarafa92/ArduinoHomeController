package smartInterface.models;

public abstract class Controller {
	
	private static String name;
	private static Switch switch1 = new Switch();
	private static Switch switch2 = new Switch();
	private static Switch switch3 = new Switch();
	private static Switch switch4 = new Switch();
	
	public static String getName() {
		return name;
	}

	public static void setName(String name) {
		Controller.name = name;
	}

	public static Switch getSwitch1() {
		return switch1;
	}

	public static Switch getSwitch2() {
		return switch2;
	}

	public static Switch getSwitch3() {
		return switch3;
	}

	public static Switch getSwitch4() {
		return switch4;
	}
}
