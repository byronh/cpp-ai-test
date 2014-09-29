#include <cdx/Application.h>
#include <cdx/Input.h>
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

    void runApplication(ApplicationListener* applicationListener) {

        // Initialize SFML
        sf::Clock deltaClock;
        sf::ContextSettings contextSettings;
        contextSettings.antialiasingLevel = applicationListener->samples;
        sf::RenderWindow window(
                sf::VideoMode(applicationListener->width, applicationListener->height),
                applicationListener->title,
                sf::Style::Close,
                contextSettings
        );

        // Initialize application
        Application& application = Application::getInstance();
        application.setWindow(&window);
        Input& input = Input::getInstance();
        applicationListener->onInitialize();

        // Main loop
        while (window.isOpen()) {

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    application.exit();
                } else if (event.type == sf::Event::LostFocus) {
                    applicationListener->onPause();
                } else if (event.type == sf::Event::GainedFocus) {
                    applicationListener->onResume();
                }
                input.onEvent(event);
            }

            window.clear();
            sf::Time dt = deltaClock.restart();
            applicationListener->onUpdate(dt.asSeconds());
            window.display();
        }

        applicationListener->onShutdown();

    }
}
