#ifndef _WEB_PAGE_H_
#define _WEB_PAGE_H_
/*
    К частным адресам относятся IP-адреса, значения которых лежат в следующих диапазонах:

10.0.0.0 — 10.255.255.255 (маска подсети для бесклассовой (CIDR) адресации: 255.0.0.0 или /8)
100.64.0.0 — 100.127.255.255 (маска подсети 255.192.0.0 или /10) -
      Данная подсеть рекомендована согласно RFC 6598 для использования
      в качестве адресов для CGN (Carrier-Grade NAT).
172.16.0.0 — 172.31.255.255 (маска подсети: 255.240.0.0 или /12)
192.168.0.0 — 192.168.255.255 (маска подсети: 255.255.0.0 или /16)
*/

//=============================================================================

const char startWebPage[] =
{
"<!DOCTYPE html>\n"
"<html>\n"
	#include "webpageHead.h"
	"<body>\n"
		"<p class='enterIPaddr' ><b>IP :</b>\n"
			"<input type='text' placeholder='xxx.xxx.xxx.xxx' value='172.16.8.23'/>\n"
		"</p>\n"
		"<div class='centerButtons'>\n"
			"<a>\n"
				"<div id='extButtons'\n"
					"class='classButtonRecipes'>\n"
					"<div id='innButtons'\n"
							"class='innerButtonRecipes'\n"
							"onclick='funcButRecipes()'>\n"
							"<big>\n"
							"Рецепты\n"
							"</big>\n"
					"</div>\n"
				"</div>\n"
			"</a>\n"
			"<a>\n"
				"<div id='extButtons'\n"
					"class='classButtonFastRun'>\n"
					"<div id='innButtons'\n"
							"class='innerButtonFastRun'\n"
							"onclick='funcButFastRun()'>\n"
							"<big>\n"
							"Быстрый<br>запуск\n"
							"</big>\n"
					"</div>\n"
				"</div>\n"
			"</a>\n"
			"<a>\n"
				"<div id='extButtons'\n"
						"class='classButtonProgs'>\n"
					"<div id='innButtons'\n"
							"class='innerButtonProgs'\n"
							"onclick='funcButProgs()'>\n"
							"<big>\n"
							"Программы\n"
							"</big>\n"
					"</div>\n"
				"</div>\n"
			"</a>\n"
		"</div>\n"
		"<br>\n"
		"<h1>\n"
		"<div id='debugPress'>debug Press</div>\n"
		"</h1>\n"
		"<br>\n"
		"<h1>\n"
		"<div id='debugRX'>receive data</div>\n"
		"</h1>\n"
		#include "webpageScript.h"
	"</body>\n"
"</html>\n"
};

//=============================================================================

const char startWebPageRecipe[] =
{
"<!DOCTYPE html>\n"
"<html>\n"
	"<head>\n"
		"<meta charset='UTF-8'>\n"
		"<title>Рецепты</title>\n"
		"<style>\n"
			"html, body\n"
			"{\n"
				"height: 80%;\n"
				"margin: 0;\n"
				"background:#000;\n"
				"color:#ddd;\n"
			"}\n"
			".centerCircle\n"
			"{\n"
				"border: 10px solid darkred;\n"
				"max-width: 100%;\n"
				"height: 70vh;\n"
				"margin: auto;\n"
				"align-items: center;\n"
				"justify-content: center;\n"
			"}\n"
		"</style>\n"
	"</head>\n"
	"<body>\n"
		"<div class='centerCircle'>\n"
			"<ul>\n"
				"<big><big><big><big>\n"
					"<li>для детей 4-6 мес.</li>\n"
					"<li>для детей с 7 мес.</li>\n"
					"<li>для детей с 8 мес.</li>\n"
					"<li>для детей с 9 мес.</li>\n"
					"<li>каши</li>\n"
					"<li>супы</li>\n"
					"<li>вторые блюда</li>\n"
					"<li>гарниры</li>\n"
					"<li>блюда на пару</li>\n"
					"<li>закуски и салаты</li>\n"
					"<li>хлеб</li>\n"
					"<li>выпечка</li>\n"
					"<li>десерты</li>\n"
					"<li>кисломолочные продуктц</li>\n"
					"<li>напитки</li>\n"
				"</big></big></big></big>\n"
			"</ul>\n"
		"</div>\n"
	"</body>\n"
"</html>\n"
};

//=============================================================================

const char startWebPageFastRun[] =
{
"<!DOCTYPE html>\n"
"<html>\n"
	"<head>\n"
		"<meta charset='UTF-8'>\n"
		"<title>Быстрый Старт</title>\n"
		"<style>\n"
			"html, body\n"
			"{\n"
				"height: 80%;\n"
				"margin: 0;\n"
				"background:#000;\n"
				"color:#ddd;\n"
			"}\n"
			".centerCircle\n"
			"{\n"
				"border: 10px solid darkred;\n"
				"max-width: 100%;\n"
				"height: 50vh;\n"
				"margin: auto;\n"
				"display: flex;\n"
				"align-items: center;\n"
				"justify-content: center;\n"
			"}\n"
			"#debugPress\n"
			"{\n"
				"border: 10px solid gray;\n"
				"max-width: 900px;\n"
				"height: 10vh;\n"
				"margin: auto;\n"
				"display: flex;\n"
				"align-items: center;\n"
				"justify-content: center;\n"
			"}\n"
		"</style>\n"
		"<div class='centerCircle'>\n"
			"<div\n"
				"id='svgRoot'>\n"
			"</div>\n"
		"</div>\n"
	"</head>\n"
	"<body>\n"
		"<big><big><big><big>\n"
		"<div id='debugPress'>debug Press</div>\n"
		"</big></big></big></big>\n"
    "<script type='text/javascript'>\n"
      "const DIAMETER = 600;\n"
      "const SVG_SIZE = DIAMETER + 12;\n"
      "const STROKE = 'black';\n"
      "const STROKE_WIDTH = '1';\n"
			"function functionCircleRed()\n"
			"{\n"
				"myLabel = document.getElementById('debugPress');\n"
				"myLabel.innerHTML = 'myColor : RED';\n"
			"}\n"
			"function functionCircleGreen()\n"
			"{\n"
				"myLabel = document.getElementById('debugPress');\n"
				"myLabel.innerHTML = 'myColor : GREEN';\n"
			"}\n"
			"function functionCircleBlue()\n"
			"{\n"
				"myLabel = document.getElementById('debugPress');\n"
				"myLabel.innerHTML = 'myColor : BLUE';\n"
			"}\n"
			"function functionCircleYellow()\n"
			"{\n"
				"myLabel = document.getElementById('debugPress');\n"
				"myLabel.innerHTML = 'myColor : YELLOW';\n"
			"}\n"
      "const getSectorPath = (x, y, outerDiameter, a1, a2) =>\n"
			"{\n"
        "const degtorad = Math.PI / 180;\n"
        "const cr = outerDiameter / 2;\n"
        "const cx1 = Math.cos(degtorad * a2) * cr + x;\n"
        "const cy1 = -Math.sin(degtorad * a2) * cr + y;\n"
        "const cx2 = Math.cos(degtorad * a1) * cr + x;\n"
        "const cy2 = -Math.sin(degtorad * a1) * cr + y;\n"
        "return `M${x} ${y} ${cx1} ${cy1} A${cr} ${cr} 0 0 1 ${cx2} ${cy2}Z`;\n"
      "};\n"
      "const svgRoot = document.getElementById('svgRoot');\n"
      "const pieChartSvgString =\n"
			"`<svg width='${SVG_SIZE}' height='${SVG_SIZE}'>\n"
				"<path\n"
					"id='MyPath'\n"
					"stroke='${STROKE}'\n"
					"stroke-width='${STROKE_WIDTH}'\n"
					"d='${getSectorPath(SVG_SIZE / 2, SVG_SIZE / 2, DIAMETER, 45, 135)}'\n"
          "fill=red\n"
					"onclick='functionCircleRed()'\n"
				"/>\n"
        "<path\n"
          "stroke='${STROKE}'\n"
          "stroke-width='${STROKE_WIDTH}'\n"
          "d='${getSectorPath(SVG_SIZE / 2, SVG_SIZE / 2, DIAMETER, 135, 225)}'\n"
          "fill=green\n"
					"onclick='functionCircleGreen()'\n"
				"/>\n"
        "<path\n"
          "stroke='${STROKE}'\n"
          "stroke-width='${STROKE_WIDTH}'\n"
          "d='${getSectorPath(SVG_SIZE / 2, SVG_SIZE / 2, DIAMETER, 225, 315)}'\n"
          "fill=blue\n"
					"onclick='functionCircleBlue()'\n"
        "/>\n"
        "<path\n"
          "stroke='${STROKE}'\n"
          "stroke-width='${STROKE_WIDTH}'\n"
          "d='${getSectorPath(SVG_SIZE / 2, SVG_SIZE / 2, DIAMETER, 315, 45)}'\n"
          "fill=yellow\n"
					"onclick='functionCircleYellow()'\n"
        "/>\n"
      "</svg>`;\n"
      "const svgNode = document.createRange().createContextualFragment(pieChartSvgString);\n"
      "svgRoot.appendChild(svgNode);\n"
    "</script>\n"
	"</body>\n"
"</html>\n"	
};

//=============================================================================

const char startWebPageProgs[] =
{
"<!DOCTYPE html>\n"
"<html>\n"
	"<head>\n"
		"<meta charset='UTF-8'>\n"
		"<title>Программы</title>\n"
		"<style>\n"
			"html, body\n"
			"{\n"
				"height: 80%;\n"
				"margin: 0;\n"
				"background:#000;\n"
				"color:#ddd;\n"
			"}\n"
			".centerButton\n"
			"{\n"
				"border: 10px solid darkred;\n"
				"max-width: 100%;\n"
				"height: 70vh;\n"
				"margin: auto;\n"
				"align-items: center;\n"
				"justify-content: center;\n"
			"}\n"
			"#tWork,#tRunning,#tGradus\n"
			"{\n"
				"margin: 7px 2px;\n"
				"padding: 25px 32px;\n"
				"font-size: 30px;\n"
				"width:40%;\n"
				"height:30%;\n"
			"}\n"
			"#tWork:hover,\n"
			"#tRunning:hover,\n"
			"#tGradus:hover\n"
			"{\n"
				"background-color: #4CAF50;\n"
				"color: white;\n"
			"}\n"
			"#debugPress\n"
			"{\n"
				"border: 10px solid gray;\n"
				"max-width: 900px;\n"
				"height: 10vh;\n"
				"margin: auto;\n"
				"display: flex;\n"
				"align-items: center;\n"
				"justify-content: center;\n"
			"}\n"
		"</style>\n"
	"</head>\n"
	"<body>\n"
		"<div class='centerButton'>\n"
			"<p style='text-align: center'>\n"
				"<button id='tWork'\n"
							"type='submit'\n"
							"onclick='func_t_work()'>\n"
							"Время работы, час/мин\n"
				"</button>\n"
			"</p>\n"
			"<p style='text-align: center'>\n"
				"<button id='tRunning'\n"
							"type='submit'\n"
							"onclick='func_t_run()'>\n"
							"Время запуска, час/мин\n"
				"</button>\n"
			"</p>\n"
			"<p style='text-align: center'>\n"
					"<button id='tGradus'\n"
							"type='submit'\n"
							"onclick='func_temperature()'>\n"
							"Температура, °C\n"
					"</button>\n"
			"</p>\n"
		"</div>\n"
		"<big><big><big><big>\n"
		"<div id='debugPress'>debug Press</div>\n"
		"</big></big></big></big>\n"
		"<script>\n"
			"//-------------------------------------\n"
			"function func_t_work()\n"
			"{\n"
				"myLabel = document.getElementById('debugPress');\n"
				"myLabel.innerHTML = 'press button (func_t_work)';\n"
				"myLabel.innerHTML += ', Время работы, час/мин';\n"
			"}\n"
			"//-------------------------------------\n"
			"function func_t_run()\n"
			"{\n"
				"myLabel = document.getElementById('debugPress');\n"
				"myLabel.innerHTML = 'press button (func_t_run)';\n"
				"myLabel.innerHTML += ', Время запуска, час/мин';\n"
			"}\n"
			"//-------------------------------------\n"
			"function func_temperature()\n"
			"{\n"
				"myLabel = document.getElementById('debugPress');\n"
				"myLabel.innerHTML = 'press button (func_temperature)';\n"
				"myLabel.innerHTML += ', Температура, °C';\n"
			"}\n"
		"</script>\n"
	"</body>\n"
"</html>\n"
};

//=============================================================================

#endif	//_WEB_PAGE_H_
