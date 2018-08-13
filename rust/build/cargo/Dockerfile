FROM  rust
RUN rustup target add x86_64-unknown-linux-musl

ONBUILD WORKDIR /usr/app
ONBUILD COPY . .
ONBUILD RUN cargo build --target x86_64-unknown-linux-musl
ONBUILD RUN cargo install --path . --root `pwd`
