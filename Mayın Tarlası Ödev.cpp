class Mines {
	public static void main(String args[]) throws Exception
	{
		java.util.Random generator = new
			java.util.Random(System.currentTimeMillis());

		int pcBoard[][] = new int[10][10];

		int plBoard[][] = new int[10][10];

		int i, j, row, col, count, isGameOver, r, c;

		row = 10;
		col = 10;

		//Mayınlar yerleştiriliyor.
		count = 0;
		while (count != 25) {
			r = generator.nextInt(10);
			c = generator.nextInt(10);
			if (pcBoard[r][c] != -1) {
				pcBoard[r][c] = -1;
				count = count + 1;
			}
		}

		for (i = 0; i < row; i = i + 1) {
			for (j = 0; j < col; j = j + 1) {
				if (pcBoard[i][j] != -1)
					System.out.print(" ");
				System.out.print(pcBoard[i][j] + " ");
			}
			System.out.println();
		}

		//Mayın olmayan hücrelerin etrafındaki mayınlar sayılıyor.
		for (i = 0; i < row; i = i + 1)
			for (j = 0; j < col; j = j + 1)
				if (pcBoard[i][j] == 9) {
					count = 0;
					for (r = i - 1; r <= i + 1; r = r + 1)
						for (c = j - 1; c <= j + 1; c = c + 1)
							if (r >= 0)
								if (r < row)
									if (c >= 0)
										if (c < col)
											if (pcBoard[r][c] == -1)
												count = count + 1;

					pcBoard[i][j] = count;
				}

		//Oyun oynanıyor.
		count = 0;
		isGameOver = 0;
		while (isGameOver == 0) {
			count = count + 1;
			System.out.print("Satiri giriniz : ");
			r = Keyboard.readInt();
			System.out.print("Sutunu giriniz : ");
			c = Keyboard.readInt();

			plBoard[r][c] = pcBoard[r][c];

			if (pcBoard[r][c] == -1) {
				isGameOver = 1;
				System.out.println("Mayina bastiniz...");
			}
			else if (count == 75) {
				isGameOver = 1;
				System.out.println("Tebrikler...");
			}

			for (i = 0; i < row; i = i + 1) {
				for (j = 0; j < col; j = j + 1) {
					if (pcBoard[i][j] != -1)
						System.out.print(" ");
					System.out.print(pcBoard[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			for (i = 0; i < row; i = i + 1) {
				for (j = 0; j < col; j = j + 1) {
					if (plBoard[i][j] != -1)
						System.out.print(" ");
					System.out.print(plBoard[i][j] + " ");
				}
				System.out.println();
			}
		}
	}
}