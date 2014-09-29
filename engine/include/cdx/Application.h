#include <SFML/Graphics/RenderWindow.hpp>


#pragma once


namespace sf {
    class RenderWindow;
}

namespace cdx {


    class Application {

    public:
        static Application& getInstance();
        ~Application() {};

        inline sf::RenderWindow* getWindow() const {
            return mWindow;
        }
        void setWindow(sf::RenderWindow* window);
        void exit();

    private:
        Application() {};
        Application(const Application& other);
        void operator=(const Application& other);

        sf::RenderWindow* mWindow;
    };


    class ApplicationListener {

    public:
        ApplicationListener() {};
        virtual ~ApplicationListener() {};

        virtual void run() final;

        virtual void onInitialize() = 0;
        virtual void onPause() = 0;
        virtual void onResume() = 0;
        virtual void onUpdate(float delta) = 0;
        virtual void onShutdown() = 0;

    public:

        const char* title = "Untitled";
        unsigned int width = 800;
        unsigned int height = 600;
        unsigned int samples = 0;

    };

    void runApplication(ApplicationListener* applicationListener);
}
