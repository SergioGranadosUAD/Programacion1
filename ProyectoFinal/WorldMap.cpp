#include "WorldMap.h"

/************************************
* @method:   WorldMap
* @access:   public
* @return    WorldMap
* @brief:    Constructor de la clase WorldMap.
* @details:  Sin detalles.
*************************************/
WorldMap::WorldMap(int sizeX, int sizeY, Player* hero, vector<Room*> rooms, map<string, bool> triggers):
m_sizeX(sizeX), m_sizeY(sizeY), m_hero(hero), m_rooms(rooms), m_triggers(triggers) {

}

/************************************
* @method:   ~WorldMap
* @access:   public
* @return    void
* @brief:    Destructor de la clase WorldMap.
* @details:  Se encarga de eliminar todos los punteros almacenados dentro de esta clase.
*************************************/
WorldMap::~WorldMap() {
	for (Room* r : m_rooms) {
		delete r;
	}
	delete m_hero;
}

/************************************
* @method:   PrintMap
* @access:   public
* @return    void
* @brief:    Este método imprime el mapa del mundo de manera estilizada.
* @details:  Revisa que los cuartos se encuentren explorados y la posición del jugador para imprimir la información de manera detallada.
*************************************/
void WorldMap::PrintMap() {
	cout << "\033[0m\t. 0 1 2 3 4 5 6" << endl;
	for (int i = 0; i < m_sizeY; ++i) {
		cout << "\t\033[0m" << i << " ";
		for (int j = 0; j < m_sizeX; ++j) {
			bool roomFound = false;
			bool playerFound = false;
			for (Room* r : m_rooms) {
				if (r->m_posX == j && r->m_posY == i && r->m_isExplored) {
					roomFound = true;
					if (m_hero->posX == j && m_hero->posY == i) {
						playerFound = true;
					}
				}
			}

			if (roomFound && playerFound) {
				cout << "\033[32m@ ";
			} else if (roomFound) {
				cout << "\033[32m# ";
			}
			else {
				cout << "\033[33m. ";
			}
		}
		cout << endl;
	}
	cout << endl << "\033[31mCoordenadas actuales: (" << m_hero->posX << "," << m_hero->posY << ")" << endl;
	cout << "\033[32m# simboliza un cuarto explorado." << endl;
	cout << "@ simboliza el cuarto en el que se encuentra el jugador\033[0m" << endl << endl;
}

/************************************
* @method:   ValidatePlayerMovement
* @access:   public
* @return    void
* @brief:	 Este método se encarga de validar si se puede realizar el movimiento del jugador y hace los cambios para reflejar este movimiento.
* @details:	 Si se realiza la validación correctamente, manda a llamar a la función MovePlayer() para mover directamente al jugador de lugar.
*************************************/
void WorldMap::ValidatePlayerMovement(const string& dir){
	if (dir == "derecha" || dir == "izquierda" || dir == "arriba" || dir == "abajo") {
		Room* playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);

		if (playerRoom->CheckMovement(dir)) {
			m_hero->MovePlayer(dir);
			playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);
			if (!playerRoom->m_isExplored) {
				playerRoom->m_isExplored = true;
			}
			cout << playerRoom->m_description << endl << endl;
		}
		else {
			cout << "No se puede mover en ese sentido." << endl;
		}
	}
	else {
		cout << "No se ha introducido una direccion correcta." << endl;
	}
	
}

/************************************
* @method:   GetRoomAtPos
* @access:   private
* @return    Room*
* @brief:	 Esta función recibe un par de coordenadas en X y en Y y devuelve el cuarto que se encuentre en esas coordenadas.
* @details:	 Sin detalles.
*************************************/
Room* WorldMap::GetRoomAtPos(const int& posX, const int& posY) {
	for (Room* r : m_rooms) {
		if (r->m_posX == posX && r->m_posY == posY) {
			return r;
		}
	}
}

/************************************
* @method:   PrintStartingText
* @access:   public
* @return    string
* @brief:	 Este método devuelve la información del cuarto en el que inicia el jugador para que se pueda imprimir antes de iniciar el loop.
* @details:	 Sin detalles.
*************************************/
string WorldMap::PrintStartingText() {
	Room* playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);
	return playerRoom->m_description;
}

/************************************
* @method:   InspectObject
* @access:   public
* @return    void
* @brief:	 Este método verifica que si un objeto/cuarto existe y devuelve la descripción de este.
* @details:	 Dependiendo de la entrada puede devolver los objetos de un cuarto o la descripcion de un objeto con ese nombre.
*************************************/
void WorldMap::InspectObject(const string& object) {
	Room* playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);
	//En caso de inspeccionar cuarto devuelve los objetos que se encuentran dentro de este.
	if (object == "cuarto") {
		if (playerRoom->m_roomItems[0] != "empty") {
			cout << "Al observar detenidamente el cuarto has podido encontrar los siguientes objetos: ";
			for (const Items& item : playerRoom->m_roomItems) {
				if (item.m_isAvailable) {
					cout << item << ", ";
				}
			}
		}
		else {
			cout << "Al observar detenidamente el cuarto no pudiste encontrar ningun objeto relevante.";
		}
	}
	//En caso contrario busca un objeto que coincida con el nombre proporcionado por el parámetro e imprime su descripción.
	else {
		bool itemFound = false;
		for (const Items& item : playerRoom->m_roomItems) {
			if (object == item) {
				cout << item.m_description;
				itemFound = true;
			}
		}
		if (!itemFound) {
			cout << "No se ha encontrado ese objeto.";
		}
	}
	cout << endl << endl;
}

/************************************
* @method:   CheckObjectInteraction
* @access:   public
* @return    GAME_STATE
* @brief:	 Este método verifica si se puede interactuar con un item proporcionado por el parámetro, y devuelve el estado del juego al terminar la interacción.
* @details:	 Dependiendo de GAME_STATE indica si el juego continuará o si se terminará de una forma determinada.
*************************************/
WorldMap::GAME_STATE WorldMap::CheckObjectInteraction(const string& object) {
	Room* playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);
	GAME_STATE gameState = NORMAL;
	string returnedItem = "";
	bool itemFound = false;
	for (Items& item : playerRoom->m_roomItems) {
		if(item == object && item.m_isAvailable){
			gameState = InteractWithItem(item, playerRoom);
			itemFound = true;
		}
		else if (item == object) {
			cout << "Ese objeto no es util de momento." << endl;
		}
	}
	if (!itemFound) {
		cout << "No se ha encontrado ese objeto." << endl;
	}
	cout << endl;
	return gameState;
}

/************************************
* @method:   ShowInventory
* @access:   public
* @return    void
* @brief:	 Este método imprime los objetos que están disponibles (marcados como true) en el inventario.
* @details:	 Sin detalles.
*************************************/
void WorldMap::ShowInventory() {
	cout << "Tengo los siguientes objetos en mi inventario: ";
	for (const auto& item : m_hero->inventory) {
		if (item.second) {
			cout << item.first << ", ";
		}
	}
	cout << endl << endl;
}

/************************************
* @method:   InteractWithItem
* @access:   public
* @return    GAME_STATE
* @brief:	 Este método realiza una acción específica dependiendo del tipo de interacción que tenga el objeto mandado por el parámetro.
* @details:	 Hay objetos que son capaces de terminar el juego, estado que se representa por medio de la devolución de un GAME_STATE que indicará
*			 el fin del juego. Cada objeto tiene su propio caso que realizará una acción propia.
*************************************/
WorldMap::GAME_STATE WorldMap::InteractWithItem(Items& item, Room* playerRoom) {
	Room* updatedRoom;
	switch (item.m_interactionType) {
	case item.PICKUP_COIN:
		item.m_isAvailable = false;
		m_hero->UpdatePlayerInventory("Moneda antigua");
		playerRoom->UpdateDescription("Ya no queda nada mas en este cuarto. La unica salida es la escalera por la que bajaste.");
		cout << "Decides agarrar la moneda que se encuentra en el piso, puede que tenga uso mas tarde." << endl;
		return NORMAL;
		break;

	case item.PICKUP_GLOVES:
		item.m_isAvailable = false;
		m_hero->UpdatePlayerInventory("Guantes de electricista");
		cout << "Decides agarrar el par de guantes de electricista, debido a que pueden ser utiles." << endl;
		return NORMAL;
		break;

	case item.PICKUP_HAMMER:
		item.m_isAvailable = false;
		m_hero->UpdatePlayerInventory("Martillo");
		playerRoom->UpdateDescription("Despues de recoger el martillo ya no queda nada mas en el cuarto. Notas puertas tanto a la derecha como a la izquierda, ademas de una escotilla que lleva a un nivel superior.");
		cout << "Decides agarrar el martillo que se encuentra en el suelo, tal vez haya algo que se pueda romper." << endl;
		return NORMAL;
		break;

	case item.PICKUP_VALVE:
		item.m_isAvailable = false;
		m_hero->UpdatePlayerInventory("Valvula de gas");
		playerRoom->UpdateDescription("Tras recoger la valvula ya no hay nada de utilidad en el cuarto. Te das cuenta de que la unica puerta del cuarto es por la cual entraste.");
		cout << "Decides agarrar la valvula de gas, debe de poder ocuparse en algun lado." << endl;
		return NORMAL;
		break;

	case item.SLOT_MACHINE:
		item.m_isAvailable = false;
		m_hero->UpdatePlayerInventory("Moneda antigua");
		m_hero->UpdatePlayerInventory("Guantes de electricista");
		cout << "Pones la moneda en el tragamonedas y la compuerta de este se abre, revelando un par de guantes de electricista, los cuales decides agarrar." << endl;
		return NORMAL;
		break;

	case item.TRANSFORMER_LEVER:
		m_triggers["transformerLeverEnabled"] = true;
		item.m_isAvailable = false;
		cout << "Bajas la palanca y puedes notar que el transformador cercano se encendio, abriendo su compuerta." << endl;

		updatedRoom = GetRoomAtPos(5, 3);
		updatedRoom->m_roomItems[1].m_description = "Al observar detenidamente este transformador puedes notar que al prenderlo se abrio una compuerta en la que parece haber una llave.\nA pesar de esto parece una muy mala idea tratar de agarrarla sin tener alguna clase de proteccion.";

		return NORMAL;
		break;

	//Esta acción es capaz de terminar el juego si no se tiene el item apropiado en el inventario.
	case item.TRANSFORMER:
		if (m_triggers["transformerLeverEnabled"] && m_hero->FindItemInInventory("Guantes de electricista")) {
			m_hero->UpdatePlayerInventory("Guantes de electricista");
			item.m_isAvailable = false;
			m_hero->UpdatePlayerInventory("Llave de diamantes");
			cout << "Te pones los guantes de electricista y obtienes la llave de diamantes de forma segura. Probablemente ya no necesites interactuar mas con el transformador." << endl;
		}
		else if (m_triggers["transformerLeverEnabled"]) {
			item.m_isAvailable = false;
			cout << "A pesar de lo peligroso que es decides intentar agarrar la llave sin ningun tipo de proteccion. Logras tocarla pero en ese instante sientes una fuerte descarga electrica recorriendote y tu vista se desvanece a negro..." << endl;
			return GAME_OVER;
		}
		else {
			cout << "No puedes hacer nada con el transformador mientras se encuentre apagado." << endl;
		}
		
		return NORMAL;
		break;

	case item.SAFE:
		if (m_hero->FindItemInInventory("Nota de codigo de cofre")) {
			item.m_isAvailable = false;
			m_hero->UpdatePlayerInventory("Nota de codigo de cofre");
			m_hero->UpdatePlayerInventory("Llave de corazones");
			cout << "Introduces el codigo en el candado del cofre y lo abres. Dentro de este habia una llave de corazones, la cual decides agarrar." << endl;
		}
		else {
			cout << "Necesitas un codigo para poder abrir este cofre." << endl;
		}
		return NORMAL;
		break;

	case item.LEVER_I:
		m_triggers["leverIEnabled"] = true;
		item.m_isAvailable = false;
		if (m_triggers["leverIEnabled"] && m_triggers["leverIIEnabled"] && m_triggers["leverIIIEnabled"]) {
			updatedRoom = GetRoomAtPos(4, 2);
			updatedRoom->m_canMoveForward = true;
			updatedRoom->UpdateDescription("Este cuarto se encuentra vacio. Parece ser que el sonido fuerte provenia de la escotilla de arriba, la cual ahora se encuentra abierta. Puedo volver por donde vine o subir a la escotilla que se acaba de abrir.");
			cout << "Al bajar la palanca puedes escuchar un 'click' bastante fuerte en otro cuarto." << endl;
		}
		else {
			cout << "Bajas la palanca pero no parece que algo haya sucedido. Probablemente haya mas palancas numeradas que deba de bajar." << endl;
		}
		return NORMAL;
		break;

	case item.LEVER_II:
		m_triggers["leverIIEnabled"] = true;
		item.m_isAvailable = false;
		if (m_triggers["leverIEnabled"] && m_triggers["leverIIEnabled"] && m_triggers["leverIIIEnabled"]) {
			updatedRoom = GetRoomAtPos(4, 2);
			updatedRoom->m_canMoveForward = true;
			updatedRoom->UpdateDescription("Este cuarto se encuentra vacio. Parece ser que el sonido fuerte provenia de la escotilla de arriba, la cual ahora se encuentra abierta. Puedo volver por donde vine o subir a la escotilla que se acaba de abrir.");
			cout << "Al bajar la palanca puedes escuchar un 'click' bastante fuerte en otro cuarto." << endl;
		}
		else {
			cout << "Bajas la palanca pero no parece que algo haya sucedido. Probablemente haya mas palancas numeradas que deba de bajar." << endl;
		}
		return NORMAL;
		break;

	case item.LEVER_III:
		m_triggers["leverIIIEnabled"] = true;
		item.m_isAvailable = false;
		if (m_triggers["leverIEnabled"] && m_triggers["leverIIEnabled"] && m_triggers["leverIIIEnabled"]) {
			updatedRoom = GetRoomAtPos(4, 2);
			updatedRoom->m_canMoveForward = true;
			updatedRoom->UpdateDescription("Este cuarto se encuentra vacio. Parece ser que el sonido fuerte provenia de la escotilla de arriba, la cual ahora se encuentra abierta. Puedo volver por donde vine o subir a la escotilla que se acaba de abrir.");
			cout << "Al bajar la palanca puedes escuchar un 'click' bastante fuerte en otro cuarto." << endl;
		}
		else {
			cout << "Bajas la palanca pero no parece que algo haya sucedido. Probablemente haya mas palancas numeradas que deba de bajar." << endl;
		}
		return NORMAL;
		break;

	case item.PEDESTAL_CLUBS_KEY:
		item.m_isAvailable = false;
		m_hero->UpdatePlayerInventory("Llave de treboles");
		cout << "Agarras la llave de treboles que se encuentra en el pedestal." << endl;
		return NORMAL;
		break;

	case item.GAS_LEVER:
		m_triggers["gasLeverEnabled"] = true;
		item.m_isAvailable = false;
		cout << "Bajas la palanca y puedes escuchar como disminuye la presion del gas en las tuberias." << endl;
		return NORMAL;
		break;

	//Esta acción es capaz de terminar el juego si no se activó el trigger apropiado por medio de otro item.
	case item.PIPE:
		if (m_hero->FindItemInInventory("Valvula de gas") && m_triggers["gasLeverEnabled"]) {
			m_hero->UpdatePlayerInventory("Valvula de gas");
			m_hero->UpdatePlayerInventory("Llave de picas");
			cout << "Intentas poner la valvula de gas y abrir el flujo. Momentos despues sientes un ligero golpe en la cabeza y te das cuenta de que una llave de picas cayo de un ducto en el techo directamente sobre ti." <<
				" Te preguntas lo peligroso que hubiera sido si no hubieras disminuido el suministro de gas." << endl;

		}
		else if (m_hero->FindItemInInventory("Valvula de gas")) {
			cout << "A pesar de lo peligroso que parece, decides poner la valvula de gas y abrir el flujo. Momentos despues sientes un fuerte impacto en tu cabeza y tu vision se desvanece a negro..." << endl;
			return GAME_OVER;
		}
		else {
			cout << "Te hace falta una valvula de gas para interactuar con la tuberia." << endl;
		}
		return NORMAL;
		break;

	case item.GIANT_POT:
		if (m_hero->FindItemInInventory("Martillo")) {
			item.m_isAvailable = false;
			m_hero->UpdatePlayerInventory("Martillo");
			m_hero->UpdatePlayerInventory("Nota de codigo de cofre");
			cout << "Usaste el martillo para romper el jarron gigante, revelando una nota que contiene el codigo de un candado de codigo, decides agarrarlo." << endl;
		}
		else {
			cout << "Te hace falta algo para romper el jarron." << endl;
		}
		return NORMAL;
		break;

	//Esta acción contiene la condición de victoria del juego. Es necesario tener cuatro items específicos para poder ganar.
	case item.STARTING_PEDESTAL:
		bool hasInteracted = false;
		if (m_hero->FindItemInInventory("Llave de diamantes")) {
			m_hero->UpdatePlayerInventory("Llave de diamantes");
			m_triggers["diamondsKeyPlaced"] = true;
			cout << "Pusiste la llave de diamantes en su lugar." << endl;
			hasInteracted = true;
		}
		if (m_hero->FindItemInInventory("Llave de corazones")) {
			m_hero->UpdatePlayerInventory("Llave de corazones");
			m_triggers["heartsKeyPlaced"] = true;
			cout << "Pusiste la llave de corazones en su lugar." << endl;
			hasInteracted = true;
		}
		if (m_hero->FindItemInInventory("Llave de treboles")) {
			m_hero->UpdatePlayerInventory("Llave de treboles");
			m_triggers["clubsKeyPlaced"] = true;
			cout << "Pusiste la llave de treboles en su lugar." << endl;
			hasInteracted = true;
		}
		if (m_hero->FindItemInInventory("Llave de picas")) {
			m_hero->UpdatePlayerInventory("Llave de picas");
			m_triggers["spadesKeyPlaced"] = true;
			cout << "Pusiste la llave de picas en su lugar." << endl;
			hasInteracted = true;
		}

		if (m_triggers["diamondsKeyPlaced"] && m_triggers["heartsKeyPlaced"] && m_triggers["clubsKeyPlaced"] && m_triggers["spadesKeyPlaced"]) {
			cout << "Introduces la ultima llave en su lugar y se escucha un estruendo muy fuerte. De la nada, se empieza a abrir el muro frente a ti, revelado la luz del exterior. Lo has logrado, eres libre." << endl;
			return WIN_CONDITION;
		}

		if (!hasInteracted) {
			cout << "No tienes nada que hacer con el pedestal." << endl;
		}
		return NORMAL;
		break;
	}
}