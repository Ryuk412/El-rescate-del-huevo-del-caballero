#include "Menu.h"

Menu::Menu() {
    _fondoTextura.loadFromFile("menu/menu_principal.png");
    _fondo.setTexture(_fondoTextura);
    _musica.reproducir(); // Inicia la música de fondo

    // Configuración de las hitboxes
    _jugarHitbox.setSize(sf::Vector2f(200, 55));
    _jugarHitbox.setPosition(300, 240);
    _jugarHitbox.setFillColor(sf::Color::Transparent);

    _opcionesHitbox.setSize(sf::Vector2f(200, 55));
    _opcionesHitbox.setPosition(300, 328);
    _opcionesHitbox.setFillColor(sf::Color::Transparent);

    _creditosHitbox.setSize(sf::Vector2f(200, 55));
    _creditosHitbox.setPosition(300, 415);
    _creditosHitbox.setFillColor(sf::Color::Transparent);

    _salirHitbox.setSize(sf::Vector2f(200, 55));
    _salirHitbox.setPosition(300, 500);
    _salirHitbox.setFillColor(sf::Color::Transparent);

    // Cargar la fuente para los textos
    _fuente.loadFromFile("menu/fuente/PixelifySans-Bold.ttf");

    // Configuración de los textos
    _jugarTexto.setFont(_fuente);
    _jugarTexto.setString("JUGAR");
    _jugarTexto.setCharacterSize(28);
    _jugarTexto.setFillColor(sf::Color::White);
    _jugarTexto.setPosition(357, 252);

    _opcionesTexto.setFont(_fuente);
    _opcionesTexto.setString("OPCIONES");
    _opcionesTexto.setCharacterSize(28);
    _opcionesTexto.setFillColor(sf::Color::White);
    _opcionesTexto.setPosition(337, 337);

    _creditosTexto.setFont(_fuente);
    _creditosTexto.setString("CRÉDITOS");
    _creditosTexto.setCharacterSize(28);
    _creditosTexto.setFillColor(sf::Color::White);
    _creditosTexto.setPosition(338, 423);

    _salirTexto.setFont(_fuente);
    _salirTexto.setString("SALIR");
    _salirTexto.setCharacterSize(28);
    _salirTexto.setFillColor(sf::Color::White);
    _salirTexto.setPosition(360, 508);
}

void Menu::procesarEventoEntrada(sf::Event &evento) {
    _musica.procesarEventoEntrada(evento);

    if (evento.type == sf::Event::MouseButtonPressed) {
        if (_enMenu) {  // Solo procesar eventos si estamos en el menú principal
            if (_jugarHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enMenu = false;  // Salimos del menú principal
                _enJugar = true;  // Vamos al submenú de "Jugar"
            } else if (_opcionesHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enMenu = false;  // Salimos del menú principal
                _enOpciones = true;  // Vamos al submenú de "Opciones"
            } else if (_creditosHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _enMenu = false;  // Salimos del menú principal
                _enCreditos = true;  // Vamos al submenú de "Créditos"
            } else if (_salirHitbox.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y)) {
                _musica.detener();
                exit(0);  // Salir del programa
            }
        }
    }

    // Procesar eventos dependiendo de cuál submenú esté activo
    if (_enJugar) {
        _jugar.procesarEventoEntrada(evento);
        if (_jugar.getVolver()) {
            _enJugar = false;  // Volvemos al menú principal
            _enMenu = true;
            _jugar.setVolver(false);
        }
    }
    else if (_enOpciones) {
        _opciones.procesarEventoEntrada(evento);
        if (_opciones.getVolver()) {
            _enOpciones = false;  // Volvemos al menú principal
            _enMenu = true;
            _opciones.setVolver(false);
        }
    }
    else if (_enCreditos) {
        _creditos.procesarEventoEntrada(evento);
        if (_creditos.getVolver()) {
            _enCreditos = false;  // Volvemos al menú principal
            _enMenu = true;
            _creditos.setVolver(false);
        }
    }
}

void Menu::dibujar(sf::RenderWindow &ventana) {
    ventana.clear();
    ventana.draw(_fondo);

    // Si estamos en el menú principal, dibujamos las opciones
    if (_enMenu) {
        ventana.draw(_jugarHitbox);
        ventana.draw(_opcionesHitbox);
        ventana.draw(_creditosHitbox);
        ventana.draw(_salirHitbox);
    }

    ventana.draw(_jugarTexto);
    ventana.draw(_opcionesTexto);
    ventana.draw(_creditosTexto);
    ventana.draw(_salirTexto);

    // Dibujar el submenú correspondiente si estamos en alguno
    if (_enJugar) {
        _jugar.dibujar(ventana);
    } else if (_enOpciones) {
        _opciones.dibujar(ventana);
    } else if (_enCreditos) {
        _creditos.dibujar(ventana);
    }
}

