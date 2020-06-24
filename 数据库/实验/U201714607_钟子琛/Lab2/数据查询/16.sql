SELECT FDay, DDay, count(*) FROM DiagnoseRecord
	WHERE DStatus = 1
	GROUP BY FDay, DDay
	ORDER BY FDay DESC, DDay DESC;