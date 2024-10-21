#pragma once
///Enumeration of types of Components
enum class ComponentType : short {
	TextureComponent, ///Component that renders a sprite texture
	Collider2DComponent, ///Component that contains a 2D collider
	TransformComponent, ///Component that controls the movement and placement of an object
	InputComponent, ///Component that handles taking user input
};
