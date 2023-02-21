#include "CapituloDiez.h"

namespace CapituloDiez {
	Symbol_table st;
	const int number = 8;
	const char printResult = ';';
	const char exitProgram = 'q';
	const char showHelp = 'h';
	const char name = 'a';
	const char let = 'v';
	const char logaritmo = 'n';
	const char from = 'f';
	const char to = 't';
	const string declkey = "let";
	const string exitkey = "quit";
	const string helpkey = "help";
	const string logkey = "log";
	const string fromkey = "from";
	const string tokey = "to";
	const string prompt = "> ";
	const string result = "= ";

	const vector<string> romanChar{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	const vector<int> romanValue{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

	//Esta función establece el valor del numero de un objeto Roman_int
	void Roman_int::SetNumber(string s) {
		if (Validate(s)) {
			number = s;
		}
	}

	bool Roman_int::Validate(string s) {
		return true; // Placeholder
	}

	//Esta función convierte un objeto de tipo Roman_int a un numero entero y lo devuelve.
	int Roman_int::as_int() {
		vector<int> charValue = GetCharValue(number);

		int prevValue = 0;
		int result = 0;
		for (int i = charValue.size()-1; i >= 0; i--) {
			if (charValue[i] < prevValue) {
				result -= charValue[i];
			}
			else if (charValue[i] >= prevValue) {
				result += charValue[i];
			}
			prevValue = charValue[i];
		}
		return result;
	}

	//Esta función regresa el valor entero de un numero romano.
	vector<int> Roman_int::GetCharValue(string s) {
		vector<int> charValue;
		for (char c : number) {
			switch (c) {
			case 'I':
				charValue.push_back(1);
				break;
			case 'V':
				charValue.push_back(5);
				break;
			case 'X':
				charValue.push_back(10);
				break;
			case 'L':
				charValue.push_back(50);
				break;
			case 'C':
				charValue.push_back(100);
				break;
			case 'D':
				charValue.push_back(500);
				break;
			case 'M':
				charValue.push_back(1000);
				break;
			default:
				error("Caracter no reconocido.");
			}
		}
		return charValue;
	}

	//Esta función verifica que el caracter introducido pertenezca a los numeros romanos.
	bool Roman_int::IsValidChar(char c) {
		switch (c) {
		case 'I':
			return true;
			break;
		case 'V':
			return true;
			break;
		case 'X':
			return true;
			break;
		case 'L':
			return true;
			break;
		case 'C':
			return true;
			break;
		case 'D':
			return true;
			break;
		case 'M':
			return true;
			break;
		default:
			return false;
		}
	}

	//Esta sobrecarga de operador permite guardar un objeto de tipo Roman_int de forma apropiada.
	istream& operator>>(istream& is, Roman_int& r) {
		is.exceptions(is.exceptions() | ios_base::badbit);
		string s = "";
		char c;
		while (is.get(c)) {
			if (r.IsValidChar(c)) {
				s += c;
			}
			else {
				is.putback(c);
				break;
			}
		}

		r.SetNumber(s);
		cout << r.GetNumber() << endl;
		return is;
	}

	//Esta sobrecarga de operador permite imprimir un objeto de tipo Roman_int de forma apropiada.
	ostream& operator<<(ostream& os, Roman_int& r) {
		os << r.GetNumber();
		return os;
	}

	//Esta función convierte un número arabigo a un número romano y lo devuelve.
	string IntToRomanInt(int val) {
		string result;
		for (int i = 0; i < 13; i++) {
			while (val - romanValue[i] >= 0) {
				result += romanChar[i];
				val -= romanValue[i];
			}
		}
		return result;
	}

/*
----------------------------------------
FUNCIONES DE LA CALCULADORA
----------------------------------------
*/


	//Esta función evalua las expresiones introducidas hasta que le indique que pare.
	void calculate() {
		PrintInstructions();
		Token_stream ts;
		while (cin) {
			try {
				cout << prompt;
				Token t = ts.get();

				while (t.kind == printResult) t = ts.get();
				if (t.kind == exitProgram) {
					break;
				}
				else if (t.kind == showHelp) {
					PrintInstructions();
				}
				ts.putback(t);
				//Se modifica la salida para que se imprima en numeros romanos.
				cout << result << IntToRomanInt(statement(ts)) << endl;
			}
			catch (runtime_error& e) {
				cerr << e.what() << endl;
				clean_up_mess(ts);
			}
		}
	}

	double statement(Token_stream& ts) {
		Token t = ts.get();
		switch (t.kind) {
		case let:
			return declaration(ts);
		default:
			ts.putback(t);
			return expression(ts);
		}
	}

	//Esta función evalua si el token se trata de una expresión ocupando las reglas gramaticales actualizadas en el capítulo 7.
	double declaration(Token_stream& ts) {
		Token t = ts.get();
		if (t.kind != name) error("Nombre esperado durante la declaracion.");
		string var_name = t.name;

		Token t2 = ts.get();
		if (t2.kind != '=') error("Falta '=' en la declaracion de la variable.");

		double d = expression(ts);
		st.define_name(var_name, d);

		return d;
	}

	//Esta función evalua si el token se trata de una expresión ocupando las reglas gramaticales ya establecidas.
	double expression(Token_stream& ts) {
		double left = term(ts);
		Token t = ts.get();
		while (true) {
			switch (t.kind) {
			case '+':
				left += term(ts);
				t = ts.get();
				break;
			case '-':
				left -= term(ts);
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
			}
		}
	}

	//Esta función evalua si el token se trata de un termino ocupando las reglas gramaticales ya establecidas.
	double term(Token_stream& ts) {
		double left = primary(ts);
		Token t = ts.get();
		while (true) {
			switch (t.kind) {
			case '*':
				left *= primary(ts);
				t = ts.get();
				break;
			case '/':
			{ double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
			}
			case '%':
			{ double d = primary(ts);
			if (d == 0) error("divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
			}
			default:
				ts.putback(t);
				return left;
			}
		}
	}

	//Esta función evalua si el token se trata de un valor primario ocupando las reglas gramaticales ya establecidas.
	double primary(Token_stream& ts) {
		Token t = ts.get();
		double d = 0;
		switch (t.kind) {
		case '{':
		{
			d = expression(ts);
			t = ts.get();
			if (t.kind != '}') error("'}' expected");
			break;
		}
		case '(':
			d = expression(ts);
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			break;
		case name:
		{ Token t2 = ts.get();
		if (t2.kind == '=') {
			d = expression(ts);
			st.set_value(t.name, d);
			return d;
		}
		else {
			ts.putback(t2);
			return st.get_value(t.name);
		}
		}
		case number:
			d = t.value;
			break;
		case logaritmo:
			double ln;
			t = ts.get();
			if (t.kind != '(') error("')' expected");
			ln = expression(ts);
			//t = ts.get();
			//if (t.kind != number) error("El valor introducido no es numerico");
			d = log(ln);
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			break;
		case '+':
			d = primary(ts);
			break;
		case '-':
			return -primary(ts);
			break;
		default:
			error("primary expected");
		}

		t = ts.get();
		if (t.kind == '!') {
			return factorial(d);
		}
		else {
			ts.putback(t);
			return d;
		}
	}

	//Esta función es usada por el ejercicio tres, calcula y devuelve la factorial de un numero si cumple con los requisitos.
	double factorial(double num) {
		if (int(num) != num) {
			error("No se puede calcular factorial para decimales.");
		}
		else if (num == 0) {
			return 1;
		}
		else {
			return(num * factorial(num - 1));
		}

	}

	//Esta función es ocupada por la clase Token_stream para guardar un token para su uso posterior.
	void Token_stream::putback(Token t)
	{
		if (full) error("putback() into a full buffer");
		buffer = t; // copy t to buffer
		full = true; // buffer is now full
	}

	//Esta función obtiene tokens del usuario y determina si se trata de un caracter valido o de un numero.
	Token Token_stream::get()
	{
		if (full) { //do we already have a Token ready ?
			full = false; //remove Token from buffer
			return buffer;
		}
		char ch;
		cin.get(ch);

		while (isspace(ch)) {
			if (ch == '\n') return Token(printResult);
			cin.get(ch);
		}

		switch (ch) {
		case printResult: //for “print”
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '{':
		case '}':
		case '!':
		case '%':
		case '=':
			return Token{ ch }; //let each character represent itself

		//Se reemplazan los numeros por numeros romanos.
		//case '.':
		//case '0': case '1': case '2': case '3': case '4':
		//case '5': case '6': case '7': case '8': case '9':
		case 'I': case 'V': case 'X': case 'L':
		case 'C': case 'D': case 'M':
		{
			cin.putback(ch); //put digit back into the input stream
			//Se crea un objeto de tipo Roman_int y se le asigna el valor. Posteriormente se convierte a decimal para que se pueda calcular.
			Roman_int val;
			cin >> val; //read a floating - point number
			return Token{ number,double(val.as_int())}; //let ‘8’ represent “a number”
		}
		default:
			if (isalpha(ch)) {
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
				cin.putback(ch);
				if (s == declkey) {
					return Token{ let };
				}
				if (s == exitkey) {
					return Token{ exitProgram };
				}
				if (s == helpkey) {
					return Token{ showHelp };
				}
				if (s == logkey) {
					return Token{ logaritmo };
				}
				if (s == fromkey) {
					return Token{ from };
				}
				if (s == tokey) {
					return Token{ to };
				}

				return Token{ name,s };
			}
			error("Bad token");
		}
	}

	//Esta función descarta todos los caracteres en el stream hasta que encuentra el caracter de salida (c).
	void Token_stream::ignore(char c) {
		if (full && c == buffer.kind) {
			full = false;
			return;
		}
		full = false;

		char ch = 0;
		while (cin >> ch)
			if (ch == c) return;
	}

	//Esta función limpia el resto de la expresión hasta encontrar el caracter de impresión, permitiendo volver a calcular sin cerrar el programa.
	void clean_up_mess(Token_stream& ts) {
		ts.ignore(printResult);
	}

	double Symbol_table::get_value(string s) {
		for (const Variable& v : var_table)
			if (v.name == s) return v.value;
		error("get: undefined variable");
	}

	void Symbol_table::set_value(string s, double d) {
		for (Variable& v : var_table) {
			if (v.name == s) {
				if (v.isConst == false) {
					v.value = d;
					return;
				}
				error("No se puede modificar una constante.");
			}
		}
		error("set: undefined variable");
	}

	bool Symbol_table::is_declared(string var) {
		for (const Variable& v : var_table)
			if (v.name == var) return true;
		return false;
	}

	double Symbol_table::define_name(string var, double val, bool b) {
		if (is_declared(var)) error("variable declarada dos veces.");
		var_table.push_back(Variable{ var,val,b });
		return val;
	}

	void PrintInstructions() {
		cout << "Esta es una calculadora sencilla." << endl;
		cout << "Introduzca la operacion matematica que desea realizar. (Acepta numeros decimales)" << endl;
		cout << "Suma: '+', Resta: '-', Multiplicacion: '*', division: '/'." << endl;
		cout << "Para calcular el resultado introduzca ';'." << endl;
		cout << "Para imprimir este mensaje nuevamente escriba 'help', para salir del programa escriba 'quit'." << endl;
	}

	//Función para arrojar errores.
	void error(string s) {
		throw runtime_error(s);
	}

}