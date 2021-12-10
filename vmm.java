import com.sun.management.OperatingSystemMXBean;
import java.lang.management.ManagementFactory;
public class vmm {
	public static void main(String[] args) {
		OperatingSystemMXBean op_sys = ManagementFactory.getPlatformMXBean(OperatingSystemMXBean.class);
		System.out.println("Phys Mem: " + op_sys.getFreePhysicalMemorySize());
		System.out.println("Virtual Mem: " + op_sys.getCommittedVirtualMemorySize());
		System.out.println("Free swap space: " + op_sys.getFreeSwapSpaceSize());
	
		double[] C = {0.5, 0.6, 0.7, 0.8, 0.9, 0.95, 0.99, 1.0, 1.01, 1.1, 1.5, 2, 5, 10, 50};
		long freeBytes = op_sys.getFreePhysicalMemorySize();

		for (int i = 0; i < 15; i++) {
			System.out.println("-----------------------\n" + "Cache Size: " + C[i] + "*M");

			double start = System.currentTimeMillis();

			int numBytes = Math.abs((int)(C[i] * (freeBytes)));
			int size = numBytes/4;
			int[] testArr = new int[size];

			System.out.println("Phys Mem: " + op_sys.getFreePhysicalMemorySize());
			System.out.println("Virtual Mem: " + op_sys.getCommittedVirtualMemorySize());
			System.out.println("Free swap space: " + op_sys.getFreeSwapSpaceSize());
			

			for (int j = 0; j < size; j++) {
				testArr[j] = i + 1;
			}
			for (int j = 0; j < size; j++) {
				testArr[j] -= 2;
			}
			
			System.out.println("Time elapsed: " + (System.currentTimeMillis() - start) + " ms");

		}
	
	
	}
}
