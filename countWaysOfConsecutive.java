	
	int countWays(int limit, boolean isSuccessiveTwo) {
		if (limit == 0)
			return 1;
		int sum = 0;
		
		if ( !isSuccessiveTwo && limit > 1  )
			sum += countWays(limit - 1,false) + countWays(limit, true);
		else	
		    sum += countWays(limit - 1, false);
		return sum;
	}
	
