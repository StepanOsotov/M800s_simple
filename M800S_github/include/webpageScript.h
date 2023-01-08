	"<script defer>	\n"
		"var countRecipes = 0;\n"
		"var countFastRun = 0;\n"
		"var countProgs = 0;\n"
		"var payloadJSON;\n"
		"var url_path;\n"
		"var attemptCounter = 0;\n"
		"function funcButRecipes()\n"
		"{\n"
			"attemptCounter = 0;\n"
			"countRecipes++;\n"
			"payloadJSON = {'bPrivate_1' : countRecipes};\n"
			"myLabel = document.getElementById('debugPress');\n"
			"myLabel.innerHTML = '>>> JSON : ' + JSON.stringify(payloadJSON);\n"
      		"url_path = f_draw_all_url();\n"
			"url_path += 'recipes';\n"
			"loadData(url_path, payloadJSON)\n"
			".then(data => {\n"
				"payloadJSON = data;\n"
				"myLabel = document.getElementById('debugRX');\n"
				"myLabel.innerHTML = '<<< RX recipe JSON : ' + countRecipes;\n"
				"var myWindow = window.open('', '_blank');\n"
				"myWindow.document.write(payloadJSON.buttonRecipes);\n"
			"});\n"
		"}\n"
		"function funcButFastRun()\n"
		"{\n"
			"attemptCounter = 0;\n"
			"countFastRun++;\n"
			"payloadJSON = {'bPrivate_2' : countFastRun};\n"
			"myLabel = document.getElementById('debugPress');\n"
			"myLabel.innerHTML = '>>> JSON : ' + JSON.stringify(payloadJSON);\n"
      		"url_path = f_draw_all_url();\n"
			"url_path += 'fastrun';\n"
			"loadData(url_path, payloadJSON)\n"
			".then(data => {\n"
				"payloadJSON = data;\n"
				"myLabel = document.getElementById('debugRX');\n"
				"myLabel.innerHTML = '<<< RX fastrun JSON : ' + countFastRun;\n"
				"var myWindow = window.open('', '_blank');\n"
				"myWindow.document.write(payloadJSON.buttonFastRun);\n"
			"});\n"
		"}\n"
		"function funcButProgs()\n"
		"{\n"
			"attemptCounter = 0;\n"
			"countProgs++;\n"
			"payloadJSON = {'bPrivate_3' : countProgs};\n"
			"myLabel = document.getElementById('debugPress');\n"
			"myLabel.innerHTML = '>>> JSON : ' + JSON.stringify(payloadJSON);\n"
      		"url_path = f_draw_all_url();\n"
			"url_path += 'progs';\n"
			"loadData(url_path, payloadJSON)\n"
			".then(data => {\n"
				"payloadJSON = data;\n"
				"myLabel = document.getElementById('debugRX');\n"
				"myLabel.innerHTML = '<<< RX progs JSON : ' + countProgs;\n"
				"var myWindow = window.open('', '_blank');\n"
				"myWindow.document.write(payloadJSON.buttonProgs);\n"
			"});\n"
		"}\n"
		"function f_draw_all_url()\n"
		"{\n"
			"return 'http://172.16.8.23/';\n"
		"}\n"
		"function MySleep(ms)\n"
		"{\n"
				"return new Promise(resolve => setTimeout(resolve, ms));\n"
		"}\n"
		"async function MyTimeoutSleep(timeUser)\n"
		"{\n"
			"for (let i = 0; i < 5; i++)\n"
			"{\n"
					"await MySleep(i * timeUser);\n"
			"}\n"
		"}\n"
		"async function loadData(url = '', dataTx = {})\n"
		"{\n"
			"try\n"
			"{\n"
				"const response = await fetchWithTimeout(url, dataTx, {\n"
					"timeout: 1000\n"
				"});\n"
				"const dataRx = await response.json();\n"
				"return dataRx;\n"
			"}\n"
			"catch (error)\n"
			"{\n"
				"if(attemptCounter >= 3)\n"
				"{\n"
					"myLabel = document.getElementById('debugRX');\n"
					"myLabel.innerHTML += ' attemptCounter = ' + attemptCounter;\n"
				"}\n"
				"else\n"
				"{\n"
					"MyTimeoutSleep(200);\n"
					"loadData(url, dataTx);\n"
					"attemptCounter++;\n"
				"}\n"
			"}\n"
		"}\n"
		"async function fetchWithTimeout(url, data, options = {})\n"
		"{\n"
			"const { timeout = 1000 } = options;\n"
			"const abortController = new AbortController();\n"
			"const id = setTimeout(() => abortController.abort(), timeout);\n"
			"const response = await fetch(url,\n"
			"{\n"
				"signal: abortController.signal,\n"
				"method: 'POST', // *GET, POST, PUT, DELETE, etc.\n"
				"mode: 'cors', // no-cors, *cors, same-origin\n"
				"cache: 'no-cache', // *default, no-cache, reload, force-cache, only-if-cached\n"
				"credentials: 'same-origin', // include, *same-origin, omit\n"
				"headers:\n"
				"{\n"
					"'Accept': 'application/json',\n"
				"},\n"
				"redirect: 'follow', // manual, *follow, error\n"
				"referrerPolicy: 'no-referrer',	// no-referrer, *no-referrer-when-downgrade, origin,\n"
																				"//origin-when-cross-origin, same-origin, strict-origin,\n"
																				"//strict-origin-when-cross-origin, unsafe-url\n"
				"body: JSON.stringify(data) // body data type must match Content-Type header\n"
			"});\n"
			"clearTimeout(id);\n"
			"return response;\n"
		"}\n"
	"</script>\n"