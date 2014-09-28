#include <cdx/Application.h>
#include <cdx/Input.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


namespace cdx {

    Application& Application::getInstance() {
        static Application instance;
        return instance;
    }

    void Application::setWindow(sf::RenderWindow* window) {
        mWindow = window;
    }

    void Application::exit() {
        if (mWindow != NULL) {
            mWindow->close();
        }
    }

    void ApplicationListener::run() {
        cdx::runApplication(this);
    }

    void runApplication(ApplicationListener* listener) {

        // Initialize SFML
        sf::RenderWindow window(sf::VideoMode(listener->width, listener->height), listener->title);
        sf::Clock deltaClock;

        //sf::CircleShape shape(100.f);
        //shape.setFillColor(sf::Color::Green);

        // Initialize application
        Application& application = Application::getInstance();
        application.setWindow(&window);
        Input& input = Input::getInstance();
        listener->onInitialize();

        // Main loop
        while (window.isOpen()) {

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    application.exit();
                } else if (event.type == sf::Event::LostFocus) {
                    listener->onPause();
                } else if (event.type == sf::Event::GainedFocus) {
                    listener->onResume();
                }
                input.onEvent(event);
            }

            sf::Time dt = deltaClock.restart();
            listener->onUpdate(dt.asSeconds());

            window.clear();
            //window.draw(shape);
            listener->onRender();
            window.display();
        }

        listener->onShutdown();

    }
}
